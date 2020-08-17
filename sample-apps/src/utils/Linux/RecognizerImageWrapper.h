#ifndef RECOGNIZER_IMAGE_WRAPPER
#define RECOGNIZER_IMAGE_WRAPPER

#include <RecognizerApi.h>

/**
 Structure that wraps image loaded with libjpeg with RecognizerImage 
 */
struct RecognizerImageWrapper {
    MBRecognizerImage * recognizerImage;
    unsigned char	  * imageBuffer;
};

typedef struct RecognizerImageWrapper RecognizerImageWrapper;

RecognizerImageWrapper loadImageFromFile    ( const char             * filePath );
void                   terminateImageWrapper( RecognizerImageWrapper * image    );

#endif