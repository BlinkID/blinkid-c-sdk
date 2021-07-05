// Created by Dominik Cubelic on 12.04.2021..
// Copyright (c) 2021 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import "MBImageRecognizer.h"

#define LICENSE_KEY "sRwAAAEWTWljcm9ibGluay5CbGlua0lERGVtb8KLCAQy0L5OgWgSAKHG/toON+iEEDbLoc70v+YGBRtquYKlefBzJjp8FMAAMnCpNY8VIDUR7fCEVAz1V3Q99ss3jWRMx0yOWk8dqfAqiqaKlg/+DfxU5AjY2yW2T3KWTuqjXCEtl3heOmDjeJvGrQaHTAcX2wslOI1e8YsrDaLQEO3FpII88495FzgoGNDVNw+WUJiUBijJfFwfivG6VelKUSsQ8kfQvcqOY0t0hIuTJpYgQ83hbJlHZVClhGtHZV6vYkEQ1yygPdRsii7SzhD4r6SMBf/usU/tDYCKBBOVSrQSnl4wH/W76MtNK+wQEuy6ji4YTKkhOkYkmgCG9UvefFU="

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
