//
//  BlinkIDTests.m
//  Demo
//
//  Created by DoDo on 11/08/2020.
//  Copyright © 2020 Microblink. All rights reserved.
//

#import "MBImageRecognizer.h"
#import <XCTest/XCTest.h>

@interface BlinkIDTests : XCTestCase

@end

@implementation BlinkIDTests

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testRecognition {
    NSString * resPath = [[NSBundle mainBundle] resourcePath];
    NSString * imagePath = [NSString stringWithFormat:@"%@/id.jpg", resPath];
    UIImage * img = [UIImage imageWithContentsOfFile:imagePath];
    CGImageRef imageRef = [img CGImage];

    int image_width = (int) CGImageGetWidth(imageRef);
    int image_height = (int) CGImageGetHeight(imageRef);
    int image_stride = (int) CGImageGetBytesPerRow(imageRef);
    
    CFDataRef rawData = CGDataProviderCopyData(CGImageGetDataProvider(imageRef));
    const void * buffer = CFDataGetBytePtr(rawData);
    
    MBRecognizerImage * image;
    recognizerImageCreateFromRawImage(&image, buffer, image_width, image_height, image_stride, MB_RAW_IMAGE_TYPE_BGRA);
    
    MBImageRecognizer * imageRecognizer = [[MBImageRecognizer alloc] init];
    MBRecognitionResult * result = [imageRecognizer performRecognition:image];
    
    XCTAssertEqualObjects(@"SAMPLE", result.firstName);
    XCTAssertEqualObjects(@"SPECIMEN", result.lastName);
}

@end
