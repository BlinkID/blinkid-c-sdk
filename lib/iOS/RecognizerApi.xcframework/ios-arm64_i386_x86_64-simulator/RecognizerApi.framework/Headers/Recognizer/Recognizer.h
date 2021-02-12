/**
 * @file Recognizer.h
 *
 * Copyright (c)2018 Microblink Ltd. All rights reserved.
 *
 * ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
 * OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
 * WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
 * UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
 * THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
 * REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.
 */

#ifndef RECOGNIZER_H_
#define RECOGNIZER_H_

#include "Export.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Typedef for pointer to generic Recognizer object.
 *
 * A Recognizer is object which orchestrates image recognition. It combines detection of objects (documents, barcodes, etc.) with
 * OCR/barcode decoding and data extraction. Each Recognizer is specific to extracting single type of information from the image.
 * For example, USDL recognizer (@see USDLRecognizer.h) is specialized for searching PDF417 barcodes on US driver's licenses and
 * extracting data from them. Please browse the documentation to see all specific available recognizers and how to configure them.
 */
typedef void * MBRecognizerPtr;

/**
 * @enum MBRecognizerResultState
 * Possible states of Recognizer's Result.
 */
enum MBRecognizerResultState
{
    /** Indicates that Recognizer's result is empty */
    MB_RECOGNIZER_RESULT_STATE_EMPTY,

    /**
     * Indicates that Recognizer's result is uncertain, i.e. some
     * data exists in it, but some data may be missing or be incomplete
     */
    MB_RECOGNIZER_RESULT_STATE_UNCERTAIN,

    /**
     * Indicates that Recognizer's result is valid, i.e. all
     * required data is present.
     */
    MB_RECOGNIZER_RESULT_STATE_VALID,

    /**
     * All mandatory information from one side of the document was extracted.
     */
    MB_RECOGNIZER_RESULT_STATE_STAGE_VALID
};

/**
 * @brief Typedef for MBRecognizerResultState enum.
 */
MB_EXPORTED_TYPE typedef enum MBRecognizerResultState MBRecognizerResultState;

/**
 * @struct MBBaseRecognizerResult
 * @brief This is base structure for all Recognizer results.
 */
struct MBBaseRecognizerResult
{
    /**
     * Indicates a state of the recognizer result.
     */
    MBRecognizerResultState state;
};


/**
 * @brief Typedef for the MBRecognizerResult structure;
 */
MB_EXPORTED_TYPE typedef struct MBBaseRecognizerResult MBBaseRecognizerResult;

#ifdef __cplusplus
}
#endif

#endif
