//
//  MBRecognition.h
//  Demo
//
//  Created by DoDo on 11/08/2020.
//  Copyright © 2020 Microblink. All rights reserved.
//

#import "MBRecognitionResult.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MBRecognition : NSObject

+ (MBRecognitionResult *) performRecognition;

@end

NS_ASSUME_NONNULL_END
