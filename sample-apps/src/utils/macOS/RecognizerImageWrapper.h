//
//  RecognizerImageWrapper.h
//  RecognizerApiDemo
//
//  Created by DoDo on 24/04/2017.
//  Copyright © 2017 DoDo. All rights reserved.
//

#ifndef RecognizerImageWrapper_h
#define RecognizerImageWrapper_h

#include <RecognizerApi.h>

struct CGImage;
typedef struct CGImage *CGImageRef;

struct __CFData;
typedef const struct __CFData * CFDataRef;

/**
 Structure that wraps CGImage with RecognizerImage 
 */
struct RecognizerImageWrapper {
    MBRecognizerImage * recognizerImage;
    CFDataRef           rawBuffer;
    CGImageRef          appleImage;
};

typedef struct RecognizerImageWrapper RecognizerImageWrapper;

RecognizerImageWrapper loadImageFromFile    ( const char             * filePath );
void                   terminateImageWrapper( RecognizerImageWrapper * image    );


#endif /* RecognizerImageWrapper_h */
