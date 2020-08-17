//
//  BlinkIDTests.m
//  Demo
//
//  Created by DoDo on 11/08/2020.
//  Copyright © 2020 Microblink. All rights reserved.
//

#import "MBRecognition.h"
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
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
    MBRecognitionResult *result = [MBRecognition performRecognition];
    XCTAssertEqualObjects(@"SAMPLE", result.firstName);
    XCTAssertEqualObjects(@"SPECIMEN", result.lastName);
}


@end
