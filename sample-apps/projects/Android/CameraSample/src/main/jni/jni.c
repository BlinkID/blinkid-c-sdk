#include <RecognizerApi.h>

#include <jni.h>

#include <android/bitmap.h>
#include <stdlib.h>
#include <assert.h>

#define LICENSE_KEY "sRwAAAAaY29tLm1pY3JvYmxpbmsuYmxpbmtpZGRlbW8GJ8vVLHPMRazjH2smaU5TkIPjPNvq0SG8YveZUxrO34xvsDmE2BldkYIoST9B7Egz12fKCYOUW/rjtrYL0lv3qosKx55HknajFB6KmVVtAv+f2jP+X2DJLHnUwLxXstTPD3HNME/9nLQfV1X0rK+qGzOBLACnmEr7s3mADFQfejH7Aq+VS+mxaqsDMcG2YU49PkYs2pWpsXTSRvRbZ6Mmcgoijwt375yXgxeXLsW9wgCcg6zbSi1ioDUzP4WY4hcX8A84uYtc"

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

    assert( errorStatus == RECOGNIZER_ERROR_STATUS_SUCCESS );

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

        assert( errorStatus == RECOGNIZER_ERROR_STATUS_SUCCESS );
    }

    {
        MBRecognizerRunnerSettings runnerSettings;

        recognizerRunnerSettingsDefaultInit( &runnerSettings );

        MBRecognizerPtr recognizers[] = { nativeContext->idRecognizer };

        runnerSettings.numOfRecognizers = 1;
        runnerSettings.recognizers = recognizers;

        errorStatus = recognizerRunnerCreate( &nativeContext->recognizerRunner, &runnerSettings );

        assert( errorStatus == RECOGNIZER_ERROR_STATUS_SUCCESS );
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
        recognizerImageSetNewRawBuffer( nativeContext->image, ( MBByte const * )image, width, height, ( size_t )width, RAW_IMAGE_TYPE_NV21 );
    }
    else
    {
        recognizerImageCreateFromRawImage( &nativeContext->image, ( MBByte const * )image, width, height, ( size_t )width, RAW_IMAGE_TYPE_NV21 );
    }

    recognizerImageSetImageOrientation( nativeContext->image, IMAGE_ORIENTATION_ROTATED_LEFT_90 );

    resultState = recognizerRunnerRecognizeFromImage( nativeContext->recognizerRunner, nativeContext->image, MB_TRUE, NULL );

    ( *env )->ReleaseByteArrayElements( env, image_, image, 0 );

    if ( resultState == RECOGNIZER_RESULT_STATE_VALID )
    {
        /* obtain the result */
        MBBlinkIdRecognizerResult result;

        blinkIdRecognizerResult( &result, nativeContext->idRecognizer );

        /* create java string from first name, you can return any data from result structure */
        return ( *env )->NewStringUTF( env, result.firstName );
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
        recognizerImageSetNewRawBuffer( nativeContext->image, ( MBByte const * ) pixelData, bitmapInfo.width, bitmapInfo.height, ( size_t )bitmapInfo.stride, RAW_IMAGE_TYPE_RGBA );
    }
    else
    {
        recognizerImageCreateFromRawImage( &nativeContext->image, ( MBByte const * ) pixelData, bitmapInfo.width, bitmapInfo.height, ( size_t )bitmapInfo.stride, RAW_IMAGE_TYPE_RGBA );
    }

    recognizerImageSetImageOrientation( nativeContext->image, IMAGE_ORIENTATION_NO_ROTATION );

    resultState = recognizerRunnerRecognizeFromImage( nativeContext->recognizerRunner, nativeContext->image, MB_FALSE, NULL );

    AndroidBitmap_unlockPixels( env, bitmap );

    if ( resultState == RECOGNIZER_RESULT_STATE_VALID )
    {
        /* obtain the result */
        MBBlinkIdRecognizerResult result;

        blinkIdRecognizerResult( &result, nativeContext->idRecognizer );

        /* create java string from first name, you can return any data from result structure */
        return ( *env )->NewStringUTF( env, result.firstName );
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
