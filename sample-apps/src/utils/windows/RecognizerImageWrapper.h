/**
* Copyright (c) Microblink Ltd. All rights reserved.
*
* ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
* OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
* WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
* UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
* THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
* REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.
*/

#pragma once

#include <RecognizerApi.h>

/**
Structure that wraps image loaded with libjpeg with RecognizerImage
*/
struct RecognizerImageWrapper {
    MBRecognizerImage * recognizerImage;
    unsigned char     * imageBuffer;
};

typedef struct RecognizerImageWrapper RecognizerImageWrapper;

RecognizerImageWrapper loadImageFromFile( const char             * filePath );
void                   terminateImageWrapper( RecognizerImageWrapper * image );
