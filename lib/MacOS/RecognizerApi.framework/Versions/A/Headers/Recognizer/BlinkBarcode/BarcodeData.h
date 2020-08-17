/**
 * @file BarcodeData.h
 *
 * Copyright (c)2017 Microblink Ltd. All rights reserved.
 *
 * ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
 * OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
 * WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
 * UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
 * THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
 * REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.
 */

#ifndef BARCODE_RESULT_INCLUDED
#define BARCODE_RESULT_INCLUDED

#include "Recognizer/Export.h"
#include "Recognizer/RecognizerError.h"
#include "Recognizer/Types.h"

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @enum MBBarcodeType
 * Possible types of barcodes.
 */
enum MBBarcodeType {
    /** Represents Aztec 2D barcode */
    BARCODE_TYPE_AZTEC,
    /** Represents Code 128 1D barcode */
    BARCODE_TYPE_CODE128,
    /** Represents Code 39 1D barcode */
    BARCODE_TYPE_CODE39,
    /** Represents DataMatrix 2D barcode */
    BARCODE_TYPE_DATA_MATRIX,
    /** Represents EAN 13 1D barcode */
    BARCODE_TYPE_EAN13,
    /** Represents EAN 8 1D barcode */
    BARCODE_TYPE_EAN8,
    /** Represents ITF 1D barcode */
    BARCODE_TYPE_ITF,
    /** Represents QR code */
    BARCODE_TYPE_QR,
    /** Represents UPC A 1D barcode */
    BARCODE_TYPE_UPCA,
    /** Represents UPC E 1D barcode */
    BARCODE_TYPE_UPCE,
    /** Represents PDF417 2D barcode */
    BARCODE_TYPE_PDF417,
    /** This is returned when result is not a barcode */
    BARCODE_TYPE_NOT_BARCODE
};

/**
 * @brief Typedef for MBBarcodeType enum.
 */
MB_EXPORTED_TYPE typedef enum MBBarcodeType MBBarcodeType;

/**
 * @brief Returns a string representation of MBBarcodeType enum. Returned pointer is a string constant.
 * @param bt MBBarcodeType value.
 * @return String representation of bt.
 */
MB_API char const * MB_CALL barcodeTypeToString( MBBarcodeType bt );

/**
 * @struct MBBarcodeData
 * @brief Structure that holds result from scanning barcode.
 */
struct MBBarcodeData {
    /** Type of barcode that was scanned */
    MBBarcodeType barcodeType;

    /** Whether or not scanned data is uncertain */
    MBBool uncertain;

    /** Zero-terminated string of data inside scanned barcode. */
    char const * stringData;

    /** Data inside barcode. Sometimes points to same memory address as stringData, but not always! */
    MBByte const * rawData;

    /** Length of buffer to which rawData points */
    size_t rawDataSize;
};

/**
 * @brief Typedef for MBBarcodeData structure.
 */
MB_EXPORTED_TYPE typedef struct MBBarcodeData MBBarcodeData;

#ifdef __cplusplus
}
#endif

#endif
