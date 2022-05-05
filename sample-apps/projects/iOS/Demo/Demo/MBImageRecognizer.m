// Created by Dominik Cubelic on 12.04.2021..
// Copyright (c) 2021 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import "MBImageRecognizer.h"

#define LICENSE_KEY "sRwAAAEWTWljcm9ibGluay5CbGlua0lERGVtb8KLCAQy0L5OgWgS8KBm8NIIg4geg5Q/idmET0xlDINBHoeScjn6Y9vOkhZa5mNNWRqx+z4tlaGhhxFsrYSm1HSnHF9B7B27AaStoxiW8UbOe4baMY72IxE00HHzfrF0VhpXCn/i0Y5AHoSt+d1p/yddK8HIEV6aC0JOP5FlMhtIjXNGgrbiw/WsfYen7k49LkNAN+28F7vD2CiKzpgh9dXn8XdmxuLxqmbDOuPVH0DCsoVrZ9bhfqNaZmG/kC16MdL1V202jQntfM8dXNmKFGUXcluH8EPYXCD1nah3zHM7us1vLov1xCxVQPmYyXcm/ZhSXBwWIWFJXKboMk18KOvT"

@interface MBImageRecognizer ()

@property (nonatomic) MBBlinkIdRecognizer *idRecognizer;
@property (nonatomic) MBRecognizerRunner *recognizerRunner;

@end

@implementation MBImageRecognizer

- (instancetype)init
{
    self = [super init];
    if (self) {
        MBBlinkIdRecognizer * idRecognizer = NULL;
        MBRecognizerRunner * recognizerRunner = NULL;

        MBRecognizerErrorStatus errorStatus = recognizerAPIUnlockWithLicenseKey(LICENSE_KEY);
        NSAssert(errorStatus == MB_RECOGNIZER_ERROR_STATUS_SUCCESS, @"Failed to unlock the app");

        NSString* resPath = [[NSBundle mainBundle] resourcePath];

        // make sure you set here the path within the app bundle that contains all required resources
        // failure to do so will result in error during creation of recognizerRunner
        errorStatus = recognizerAPISetResourcesLocation([resPath UTF8String]);
        NSAssert(errorStatus == MB_RECOGNIZER_ERROR_STATUS_SUCCESS, @"Failed to set SDK resources path!");

        MBBlinkIdRecognizerSettings idSett;
        blinkIdRecognizerSettingsDefaultInit(&idSett);

        errorStatus = blinkIdRecognizerCreate(&idRecognizer, &idSett);
        NSAssert(errorStatus == MB_RECOGNIZER_ERROR_STATUS_SUCCESS, @"Failed to create ID recognizer");

        MBRecognizerRunnerSettings runnerSett;
        recognizerRunnerSettingsDefaultInit(&runnerSett);

        MBRecognizerPtr recognizers[] = {idRecognizer};

        runnerSett.numOfRecognizers = 1;
        runnerSett.recognizers = recognizers;

        errorStatus = recognizerRunnerCreate(&recognizerRunner, &runnerSett);
        NSAssert(errorStatus == MB_RECOGNIZER_ERROR_STATUS_SUCCESS, @"Failed to create recognizer runner");

        self.recognizerRunner = recognizerRunner;
        self.idRecognizer = idRecognizer;
    }
    return self;
}

- (void)dealloc
{
    MBRecognizerRunner * recognizerRunner = self.recognizerRunner;
    MBBlinkIdRecognizer * idRecognizer = self.idRecognizer;

    recognizerRunnerDelete(&recognizerRunner);
    blinkIdRecognizerDelete(&idRecognizer);
}

- (MBRecognitionResult *)performRecognition:(MBRecognizerImage *)image {
    recognizerRunnerRecognizeFromImage(self.recognizerRunner, image, MB_FALSE, NULL);

    MBBlinkIdRecognizerResult result;
    blinkIdRecognizerResult(&result, self.idRecognizer);

    MBRecognitionResult *recognitionResult = [[MBRecognitionResult alloc] init];
    recognitionResult.firstName = [NSString stringWithUTF8String:result.common.firstName];
    recognitionResult.lastName = [NSString stringWithUTF8String:result.common.lastName];

    recognizerImageDelete(&image);
    recognizerRunnerReset(self.recognizerRunner);

    return recognitionResult;
}

@end
