//
//  MBRecognition.m
//  Demo
//
//  Created by DoDo on 11/08/2020.
//  Copyright © 2020 Microblink. All rights reserved.
//

#import "MBRecognition.h"
#import <UIKit/UIKit.h>

#import <RecognizerApi.h>

#define LICENSE_KEY "sRwAAAEWTWljcm9ibGluay5CbGlua0lERGVtb8KLCARU0L5OgWgSAKCG/dap8Em+G9mnRvI8ELnERk+Nunvm9oUA02uCIOlcf0tPHA5NjIcnu+oimIm58UV1FNj9R67HdgTlvrTZdLqDb0JNGGWVVreyOTpj5g8ii+O6kXDZTZ3IHKV0HoEhT20MRA4RxYvO53zvhSILeH9ySy50hWZiiJImntD83cVJQnErG85RxXkFKI+IQZKoy2KAT4ncC8WBVVvqg7ZG6/OG33i+DberGvgNTn2ncX4oiRHu+mB94HGkMA=="


@implementation MBRecognition

+ (MBRecognitionResult *) performRecognition {

    NSString* resPath = [[NSBundle mainBundle] resourcePath];

    MBRecognizerErrorStatus errorStatus = recognizerAPIUnlockWithLicenseKey( LICENSE_KEY );

    NSAssert( errorStatus == RECOGNIZER_ERROR_STATUS_SUCCESS, @"Failed to unlock the app" );

    // make sure you set here the path within the app bundle that contains all required resources
    // failure to do so will result in error during creation of recognizerRunner
    errorStatus = recognizerAPISetResourcesLocation( [resPath UTF8String] );

    NSAssert( errorStatus == RECOGNIZER_ERROR_STATUS_SUCCESS, @"Failed to set SDK resources path!" );

    MBBlinkIdRecognizer * idRecognizer    = NULL;
    MBRecognizerRunner  * recognizerRunner = NULL;

    MBBlinkIdRecognizerSettings idSett;

    blinkIdRecognizerSettingsDefaultInit( &idSett );

    errorStatus = blinkIdRecognizerCreate( &idRecognizer, &idSett );

    NSAssert( errorStatus == RECOGNIZER_ERROR_STATUS_SUCCESS, @"Failed to create ID recognizer" );

    MBRecognizerRunnerSettings runnerSett;

    recognizerRunnerSettingsDefaultInit( &runnerSett );

    MBRecognizerPtr recognizers[] = { idRecognizer };

    runnerSett.numOfRecognizers = 1;
    runnerSett.recognizers = recognizers;

    errorStatus = recognizerRunnerCreate( &recognizerRunner, &runnerSett );

    NSAssert( errorStatus == RECOGNIZER_ERROR_STATUS_SUCCESS, @"Failed to create recognizer runner" );

    // load image from resources
    NSString* imagePath = [NSString stringWithFormat:@"%@/id.jpg", resPath];

    UIImage* img = [UIImage imageWithContentsOfFile:imagePath];

    NSAssert( img != nil, @"Failed to load image!" );

    // create image
    MBRecognizerImage * image;

    CGImageRef imageRef = [img CGImage];
    int image_width = (int) CGImageGetWidth( imageRef );
    int image_height = (int) CGImageGetHeight( imageRef );
    int image_stride = (int) CGImageGetBytesPerRow( imageRef );

    CFDataRef rawData = CGDataProviderCopyData( CGImageGetDataProvider( imageRef ) );
    const void* buffer = CFDataGetBytePtr( rawData );

    errorStatus = recognizerImageCreateFromRawImage( &image, buffer, image_width, image_height, image_stride, RAW_IMAGE_TYPE_BGRA );

    NSAssert( errorStatus == RECOGNIZER_ERROR_STATUS_SUCCESS, @"Failed to create image" );

    MBRecognizerResultState resultState = recognizerRunnerRecognizeFromImage( recognizerRunner, image, MB_FALSE, NULL );

    NSAssert( resultState == RECOGNIZER_RESULT_STATE_VALID, @"Recognition failed" );

    MBBlinkIdRecognizerResult result;

    blinkIdRecognizerResult( &result, idRecognizer );

    NSLog(@"First name: %s, Last name: %s", result.firstName, result.lastName );

    MBRecognitionResult *recognitionResult = [[MBRecognitionResult alloc] init];
    recognitionResult.firstName = [NSString stringWithUTF8String:result.firstName];
    recognitionResult.lastName = [NSString stringWithUTF8String:result.lastName];

    recognizerRunnerDelete( &recognizerRunner );
    blinkIdRecognizerDelete( &idRecognizer );

    recognizerImageDelete( &image );

    CFRelease( rawData );
    return recognitionResult;
}

@end
