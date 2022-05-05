/**
* Copyright (c) Microblink Ltd. All rights reserved.
*
* ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
* OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
* WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
* UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
* THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
* REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.
*/

#include <RecognizerApi.h>

#include <jni.h>

#include <android/bitmap.h>
#include <stdlib.h>
#include <assert.h>

#define LICENSE_KEY "sRwAAAAaY29tLm1pY3JvYmxpbmsuYmxpbmtpZGRlbW8GJ8vVSnPMRazjHxshmWr+lTjM8djyrbPmWwO86n+PbA7gZK12gg1nHOJizws6DNOBPycDmjT5eWXvxEOJlbJOXbv1lyGHwam+hv0RB6XsF7VhdWXofY6Vf80Yv6BHUJtUsNzk5Uh4NEQtCAiYDODEad9/wmmjSnKKDB0BXEhJvOJskeOpJwFXgFoHsEccMP4rRsxB7/42tLTpmvhZK0uNP3fxHvsI177apTo5SESWcZmoSNk6MpDN8aezKYgcwk9qGAlVbu/1awtlQZqGpKOhYTiM964JkrM5YECiBbjdpoKfJyyaS/9YhLBf7ImDLEAAd+q9jGr9UEGXrWAEKkLRqw=="

struct NativeContext
{
    MBBlinkIdRecognizer * idRecognizer;
    MBRecognizerRunner  * recognizerRunner;
    MBRecognizerImage   * image;
};

typedef struct NativeContext NativeContext;

JNIEXPORT void JNICALL
Java_com_microblink_recognizerApi_IdRecognizer_initializeApplication
(
    JNIEnv *env,
    jclass type,
    jobject applicationContext
)
{
    recognizerAPIInitializeAndroidApplication( env, applicationContext );

    // define path to resources relative to assets root
    recognizerAPISetResourcesLocation( "" );
}

JNIEXPORT void JNICALL
Java_com_microblink_recognizerApi_IdRecognizer_nativeTerminate( JNIEnv *env,
                                                                jclass type,
                                                                jlong jNativeContext )
{
    NativeContext * nativeContext = ( NativeContext * )jNativeContext;

    recognizerRunnerDelete ( &nativeContext->recognizerRunner );
    blinkIdRecognizerDelete( &nativeContext->idRecognizer     );
    if ( nativeContext->image != NULL )
    {
        recognizerImageDelete( &nativeContext->image );
    }

    free( nativeContext );
}

JNIEXPORT jlong JNICALL
Java_com_microblink_recognizerApi_IdRecognizer_nativeConstruct( JNIEnv *env, jclass type )
{
    NativeContext * nativeContext;
    MBRecognizerErrorStatus errorStatus;

    /* first unlock the SDK */
    errorStatus = recognizerAPIUnlockWithLicenseKey( LICENSE_KEY );

    assert( errorStatus == MB_RECOGNIZER_ERROR_STATUS_SUCCESS );

    /*
     * Now initialize ID recognizer and recognizer runner.
     * For more detailed explanation of each line, check the demo app for desktop.
     */
    nativeContext = ( NativeContext * ) malloc( sizeof( NativeContext ) );

    nativeContext->image            = NULL;
    nativeContext->recognizerRunner = NULL;
    nativeContext->idRecognizer     = NULL;

    {
        MBBlinkIdRecognizerSettings sett;

        blinkIdRecognizerSettingsDefaultInit( &sett );

        errorStatus = blinkIdRecognizerCreate( &nativeContext->idRecognizer, &sett );

        assert( errorStatus == MB_RECOGNIZER_ERROR_STATUS_SUCCESS );
    }

    {
        MBRecognizerRunnerSettings runnerSettings;

        recognizerRunnerSettingsDefaultInit( &runnerSettings );

        MBRecognizerPtr recognizers[] = { nativeContext->idRecognizer };

        runnerSettings.numOfRecognizers = 1;
        runnerSettings.recognizers = recognizers;

        errorStatus = recognizerRunnerCreate( &nativeContext->recognizerRunner, &runnerSettings );

        assert( errorStatus == MB_RECOGNIZER_ERROR_STATUS_SUCCESS );
    }

    return ( jlong )nativeContext;
}

JNIEXPORT jstring JNICALL
Java_com_microblink_recognizerApi_IdRecognizer_nativeProcessVideoFrame
(
    JNIEnv   * env,
    jclass     type,
    jlong      jNativeContext,
    jbyteArray image_,
    jint       width,
    jint       height
)
{
    MBRecognizerResultState resultState;

    jbyte * image = ( *env )->GetByteArrayElements( env, image_, NULL);
    NativeContext * nativeContext = ( NativeContext * )jNativeContext;

    /* if image already exists, reuse it */

    if ( nativeContext->image != NULL )
    {
        recognizerImageSetNewRawBuffer( nativeContext->image, ( MBByte const * )image, width, height, ( size_t )width, MB_RAW_IMAGE_TYPE_NV21 );
    }
    else
    {
        recognizerImageCreateFromRawImage( &nativeContext->image, ( MBByte const * )image, width, height, ( size_t )width, MB_RAW_IMAGE_TYPE_NV21 );
    }

    recognizerImageSetImageOrientation( nativeContext->image, MB_IMAGE_ORIENTATION_ROTATED_LEFT_90 );

    resultState = recognizerRunnerRecognizeFromImage( nativeContext->recognizerRunner, nativeContext->image, MB_TRUE, NULL );

    ( *env )->ReleaseByteArrayElements( env, image_, image, 0 );

    if ( resultState == MB_RECOGNIZER_RESULT_STATE_VALID )
    {
        /* obtain the result */
        MBBlinkIdRecognizerResult result;

        blinkIdRecognizerResult( &result, nativeContext->idRecognizer );

        /* create java string from first name, you can return any data from result structure */
        return ( *env )->NewStringUTF( env, result.common.firstName );
    }
    else
    {
        return NULL;
    }
}

JNIEXPORT jstring JNICALL
Java_com_microblink_recognizerApi_IdRecognizer_nativeProcessBitmap
(
    JNIEnv * env,
    jclass clazz,
    jlong jNativeContext,
    jobject bitmap
)
{
    MBRecognizerResultState resultState;
    NativeContext * nativeContext = ( NativeContext * )jNativeContext;

    // obtain pixels from bitmap
    AndroidBitmapInfo bitmapInfo;

    // first initialize info struct to default
    bitmapInfo.width  = 0;
    bitmapInfo.height = 0;
    bitmapInfo.stride = 0;
    bitmapInfo.format = 0;
    bitmapInfo.flags  = 0;

    // now obtain information about bitmap
    AndroidBitmap_getInfo( env, bitmap, &bitmapInfo );

    void * pixelData = NULL;
    AndroidBitmap_lockPixels( env, bitmap, &pixelData );

    /* if image already exists, reuse it */

    if ( nativeContext->image != NULL )
    {
        recognizerImageSetNewRawBuffer( nativeContext->image, ( MBByte const * ) pixelData, bitmapInfo.width, bitmapInfo.height, ( size_t )bitmapInfo.stride, MB_RAW_IMAGE_TYPE_RGBA );
    }
    else
    {
        recognizerImageCreateFromRawImage( &nativeContext->image, ( MBByte const * ) pixelData, bitmapInfo.width, bitmapInfo.height, ( size_t )bitmapInfo.stride, MB_RAW_IMAGE_TYPE_RGBA );
    }

    recognizerImageSetImageOrientation( nativeContext->image, MB_IMAGE_ORIENTATION_NO_ROTATION );

    resultState = recognizerRunnerRecognizeFromImage( nativeContext->recognizerRunner, nativeContext->image, MB_FALSE, NULL );

    AndroidBitmap_unlockPixels( env, bitmap );

    if ( resultState == MB_RECOGNIZER_RESULT_STATE_VALID )
    {
        /* obtain the result */
        MBBlinkIdRecognizerResult result;

        blinkIdRecognizerResult( &result, nativeContext->idRecognizer );

        /* create java string from first name, you can return any data from result structure */
        return ( *env )->NewStringUTF( env, result.common.firstName );
    }
    else
    {
        return NULL;
    }
}

JNIEXPORT void JNICALL
Java_com_microblink_recognizerApi_IdRecognizer_nativeResetRecognizer
(
    JNIEnv *env,
    jclass type,
    jlong jNativeContext
)
{
    NativeContext * nativeContext = ( NativeContext * )jNativeContext;

    recognizerRunnerReset( nativeContext->recognizerRunner );
}
