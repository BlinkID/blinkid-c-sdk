//
//  RecognizerImageWrapper.m
//  RecognizerApiDemo
//
//  Created by DoDo on 24/04/2017.
//  Copyright © 2017 DoDo. All rights reserved.
//

#import "RecognizerImageWrapper.h"

#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

// taken from https://developer.apple.com/library/content/documentation/GraphicsImaging/Conceptual/ImageIOGuide/imageio_source/ikpg_source.html
RecognizerImageWrapper loadImageFromFile( const char* filePath )
{
    CGImageRef             myImage = NULL;
    CGImageSourceRef       myImageSource;
    CFDictionaryRef        myOptions = NULL;
    CFStringRef            myKeys[2];
    CFTypeRef              myValues[2];
    RecognizerImageWrapper wrapper;

    NSString* path = [NSString stringWithUTF8String:filePath];

    // Get the URL for the pathname passed to the function.
    NSURL *url = [NSURL fileURLWithPath:path];

    wrapper.appleImage      = NULL;
    wrapper.rawBuffer       = NULL;
    wrapper.recognizerImage = NULL;

    // Set up options if you want them. The options here are for
    // caching the image in a decoded form and for using floating-point
    // values if the image format supports them.
    myKeys[0] = kCGImageSourceShouldCache;
    myValues[0] = (CFTypeRef)kCFBooleanTrue;
    myKeys[1] = kCGImageSourceShouldAllowFloat;
    myValues[1] = (CFTypeRef)kCFBooleanTrue;
    // Create the dictionary
    myOptions = CFDictionaryCreate(NULL, (const void **) myKeys,
                                   (const void **) myValues, 2,
                                   &kCFTypeDictionaryKeyCallBacks,
                                   & kCFTypeDictionaryValueCallBacks);
    // Create an image source from the URL.
    myImageSource = CGImageSourceCreateWithURL((CFURLRef)url, myOptions);
    CFRelease(myOptions);
    // Make sure the image source exists before continuing
    if (myImageSource == NULL)
    {
        fprintf(stderr, "Image source is NULL.");
        return  wrapper;
    }
    // Create an image from the first item in the image source.
    myImage = CGImageSourceCreateImageAtIndex(myImageSource,
                                              0,
                                              NULL);

    CFRelease(myImageSource);
    // Make sure the image exists before continuing
    if (myImage == NULL)
    {
        fprintf(stderr, "Image not created from image source.");
        return wrapper;
    }

    int image_stride = (int) CGImageGetBytesPerRow( myImage );
    int image_width  = (int) CGImageGetWidth( myImage );
    int image_height = (int) CGImageGetHeight( myImage );

    // obtaining pixel data from CGImage: http://stackoverflow.com/a/10412292
    CFDataRef rawData = CGDataProviderCopyData( CGImageGetDataProvider( myImage ) );
    const void* buffer = CFDataGetBytePtr( rawData );

    wrapper.appleImage = myImage;
    wrapper.rawBuffer = rawData;
    recognizerImageCreateFromRawImage(&wrapper.recognizerImage, buffer, image_width, image_height, image_stride, MB_RAW_IMAGE_TYPE_BGRA);
    return wrapper;
}

void terminateImageWrapper( RecognizerImageWrapper * image )
{
    recognizerImageDelete( &image->recognizerImage );

    CFRelease( image->rawBuffer );
    CGImageRelease( image->appleImage );
}
