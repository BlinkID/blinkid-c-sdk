// Created by Dominik Cubelic on 12.04.2021..
// Copyright (c) 2021 Microblink Ltd. All rights reserved.

// ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
// OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
// WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
// UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
// THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
// REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.

#import "RecognizerViewController.h"
#import <AVFoundation/AVFoundation.h>

#import "MBImageRecognizer.h"

@interface RecognizerViewController () <AVCaptureVideoDataOutputSampleBufferDelegate>

@property (nonatomic) AVCaptureSession * captureSession;
@property (nonatomic) AVCaptureVideoPreviewLayer * videoPreviewLayer;
@property (nonatomic) AVCaptureVideoDataOutput * videoDataOutput;

@property (nonatomic) MBImageRecognizer * imageRecognizer;

@property (nonatomic, assign) BOOL paused;

@end

@implementation RecognizerViewController

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];

    self.paused = false;
    self.imageRecognizer = [[MBImageRecognizer alloc] init];
    [self setupCamera];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];

    [self.captureSession stopRunning];
}

- (AVCaptureVideoOrientation)interfaceOrientationToVideoOrientation:(UIInterfaceOrientation)orientation {
  switch (orientation) {
    case UIInterfaceOrientationPortrait:
        return AVCaptureVideoOrientationPortrait;
    case UIInterfaceOrientationPortraitUpsideDown:
        return AVCaptureVideoOrientationPortraitUpsideDown;
    case UIInterfaceOrientationLandscapeLeft:
        return AVCaptureVideoOrientationLandscapeLeft;
    case UIInterfaceOrientationLandscapeRight:
        return AVCaptureVideoOrientationLandscapeRight;
    default:
        break;
  }
  return AVCaptureVideoOrientationPortrait;
}

- (void)viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator {
    [super viewWillTransitionToSize:size withTransitionCoordinator:coordinator];
    
    [coordinator animateAlongsideTransitionInView:self.view animation:^(id<UIViewControllerTransitionCoordinatorContext>  _Nonnull context) {
        self.videoPreviewLayer.frame = self.view.bounds;
        self.videoPreviewLayer.connection.videoOrientation = [self interfaceOrientationToVideoOrientation:[UIApplication sharedApplication].statusBarOrientation];
    } completion:nil];
}

- (void)setupCamera {
    self.captureSession = [AVCaptureSession new];
    self.captureSession.sessionPreset = AVCaptureSessionPresetHigh;
    
    AVCaptureDevice * camera = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
    
    [camera lockForConfiguration:NULL];
    camera.focusMode = AVCaptureFocusModeContinuousAutoFocus;
    [camera unlockForConfiguration];
    
    AVCaptureDeviceInput * input = [AVCaptureDeviceInput deviceInputWithDevice:camera error:NULL];
    AVCaptureVideoDataOutput * output = [[AVCaptureVideoDataOutput alloc] init];
    
    NSDictionary *outputSettings = [NSDictionary dictionaryWithObject:[NSNumber numberWithInt:kCVPixelFormatType_32BGRA] forKey:(id)kCVPixelBufferPixelFormatTypeKey];
    output.videoSettings = outputSettings;
    [output setSampleBufferDelegate:self queue:dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0)];
    
    [self.captureSession addInput:input];
    [self.captureSession addOutput:output];
    
    self.videoPreviewLayer = [AVCaptureVideoPreviewLayer layerWithSession:self.captureSession];
    self.videoPreviewLayer.videoGravity = AVLayerVideoGravityResizeAspectFill;
    self.videoPreviewLayer.connection.videoOrientation = AVCaptureVideoOrientationPortrait;
    
    [self.view.layer addSublayer:self.videoPreviewLayer];
    
    dispatch_queue_t globalQueue =  dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0);
    dispatch_async(globalQueue, ^{
        [self.captureSession startRunning];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            self.videoPreviewLayer.frame = self.view.bounds;
        });
    });
}

- (MBRecognizerImage *)newRecognizerImageFrom:(CMSampleBufferRef)sampleBuffer {
    CVImageBufferRef imageBuffer = CMSampleBufferGetImageBuffer(sampleBuffer);
    CVPixelBufferLockBaseAddress(imageBuffer, 0);
    
    int image_width = (int) CVPixelBufferGetWidth(imageBuffer);
    int image_height = (int) CVPixelBufferGetHeight(imageBuffer);
    int image_stride = (int) CVPixelBufferGetBytesPerRow(imageBuffer);

    CFDataRef rawData = CFDataCreateWithBytesNoCopy(NULL, (unsigned char *) CVPixelBufferGetBaseAddress(imageBuffer), image_stride * image_height, NULL);
    unsigned char const * buffer = CFDataGetBytePtr(rawData);
    
    MBRecognizerImage * image;
    MBRecognizerErrorStatus errorStatus = recognizerImageCreateFromRawImage(&image, buffer, image_width, image_height, image_stride, MB_RAW_IMAGE_TYPE_BGRA);
    NSAssert(errorStatus == MB_RECOGNIZER_ERROR_STATUS_SUCCESS, @"Failed to create image");

    return image;
}

// MARK: - AVCaptureVideoDataOutputSampleBufferDelegate

- (void)captureOutput:(AVCaptureOutput *)output didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer fromConnection:(AVCaptureConnection *)connection {
    if (self.paused) {
        return;
    }
    
    MBRecognizerImage * image = [self newRecognizerImageFrom:sampleBuffer];
    
    MBRecognitionResult * result = [self.imageRecognizer performRecognition:image];
        
    if ([result.firstName length] > 0 && [result.lastName length] > 0) {
        
        dispatch_async(dispatch_get_main_queue(), ^{
            NSString * message = [NSString stringWithFormat:@"Hello %@ %@", result.firstName, result.lastName];
            UIAlertController * alert = [UIAlertController alertControllerWithTitle:message message:@"" preferredStyle:UIAlertControllerStyleAlert];
            
            [self presentViewController:alert animated:YES completion:nil];
            
            int alertDuration = 1;
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, alertDuration * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
                [alert dismissViewControllerAnimated:YES completion:nil];
                self.paused = false;
            });
        });
        
        self.paused = true;
    }
    
}

@end
