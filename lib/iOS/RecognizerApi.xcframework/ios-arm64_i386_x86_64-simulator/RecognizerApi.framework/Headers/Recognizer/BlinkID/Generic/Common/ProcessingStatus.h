/**
* @file ProcessingStatus.h
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
#ifndef PROCESSING_STATUS_H_INCLUDED
#define PROCESSING_STATUS_H_INCLUDED

#include <Recognizer/Export.h>

/** Detailed information about the recognition process. */
enum MBProcessingStatus
{
    /** Recognition was successful. */
    MB_PROCESSING_STATUS_SUCCESS = 0,

    /** Detection of the document failed. */
    MB_PROCESSING_STATUS_DETECTION_FAILED,

    /** Preprocessing of the input image has failed. */
    MB_PROCESSING_STATUS_IMAGE_PREPROCESSING_FAILED,

    /** Recognizer has inconsistent results. */
    MB_PROCESSING_STATUS_STABILITY_TEST_FAILED,

    /** Wrong side of the document has been scanned. */
    MB_PROCESSING_STATUS_SCANNING_WRONG_SIDE,

    /** Identification of the fields present on the document has failed. */
    MB_PROCESSING_STATUS_FIELD_IDENTIFICATION_FAILED,

    /** Mandatory field for the specific document is missing. */
    MB_PROCESSING_STATUS_MANDATORY_FIELD_MISSING,

    /** Result contains invalid characters in some of the fields. */
    MB_PROCESSING_STATUS_INVALID_CHARACTERS_FOUND,

    /** Failed to return a requested image. */
    MB_PROCESSING_STATUS_IMAGE_RETURN_FAILED,

    /** Reading or parsing of the barcode has failed. */
    MB_PROCESSING_STATUS_BARCODE_RECOGNITION_FAILED,

    /** Parsing of the MRZ has failed. */
    MB_PROCESSING_STATUS_MRZ_PARSING_FAILED,

    /** Document class has been filtered out. */
    MB_PROCESSING_STATUS_CLASS_FILTERED,

    /** Document currently not supported by the recognizer. */
    MB_PROCESSING_STATUS_UNSUPPORTED_CLASS,

    /** License for the detected document is missing. */
    MB_PROCESSING_STATUS_UNSUPPORTED_BY_LICENSE,

    /** Front side recognition has completed successfully, and recognizer is waiting for the other side to be scanned. */
    MB_PROCESSING_STATUS_AWAITING_OTHER_SIDE,

    /** Number of possible values */
    MB_PROCESSING_STATUS_COUNT
};

/**
* @brief Typedef for MBProcessingStatus enum.
*/
MB_EXPORTED_TYPE typedef enum MBProcessingStatus MBProcessingStatus;
#endif
