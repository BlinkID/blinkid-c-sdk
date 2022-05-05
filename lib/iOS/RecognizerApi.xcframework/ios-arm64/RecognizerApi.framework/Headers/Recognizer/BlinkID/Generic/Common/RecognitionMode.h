/**
* @file RecognitionMode.h
*
* Copyright (c)2020 Microblink Ltd. All rights reserved.
*
* ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
* OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
* WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
* UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
* THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
* REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.
*/
#ifndef RECOGNITION_MODE_H_INCLUDED
#define RECOGNITION_MODE_H_INCLUDED

#include <Recognizer/Export.h>

/**
 * RecognitionMode enum defines possible recognition modes by BlinkID(Combined)Recognizer.
 */
enum MBRecognitionMode
{
    /** No recognition performed. */
    MB_RECOGNITION_MODE_NONE             = 0,

    /** Recognition of mrz document (does not include visa and passport) */
    MB_RECOGNITION_MODE_MRZ_ID           = 1,

    /** Recognition of visa mrz. */
    MB_RECOGNITION_MODE_MRZ_VISA         = 2,

    /** Recognition of passport mrz. */
    MB_RECOGNITION_MODE_MRZ_PASSPORT     = 3,

    /** Recognition of documents that have face photo on the front. */
    MB_RECOGNITION_MODE_PHOTO_ID         = 4,

    /** Detailed document recognition. */
    MB_RECOGNITION_MODE_FULL_RECOGNITION = 5,

    /** Recognition of barcode document. */
    MB_RECOGNITION_MODE_BARCODE_ID       = 6,

    /** Number of possible values */
    MB_RECOGNITION_MODE_COUNT            = 7
};

/**
* @brief Typedef for MBRecognitionMode enum.
*/
MB_EXPORTED_TYPE typedef enum MBRecognitionMode MBRecognitionMode;

#endif
