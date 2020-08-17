//
//  ViewController.m
//  Demo
//
//  Created by DoDo on 21/12/2018.
//  Copyright © 2018 Microblink. All rights reserved.
//

#import "MBRecognition.h"

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (IBAction)buttonTouchDown:(id)sender {
    MBRecognitionResult *result = [MBRecognition performRecognition];

    NSString *message = [NSString stringWithFormat:@"Hello %@ %@", result.firstName, result.lastName];

    UIAlertView *toast = [[UIAlertView alloc] initWithTitle:nil
                                                    message:message
                                                   delegate:nil
                                          cancelButtonTitle:nil
                                          otherButtonTitles:nil, nil];
    [toast show];

    int duration = 1; // duration in seconds

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, duration * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
        [toast dismissWithClickedButtonIndex:0 animated:YES];
    });
}


@end
