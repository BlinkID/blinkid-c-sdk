/**
 * @file BarcodeRecognizer.h
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

#ifndef BARCODE_RECOGNIZER_INCLUDED
#define BARCODE_RECOGNIZER_INCLUDED

#include "Recognizer/Export.h"
#include "Recognizer/RecognizerError.h"
#include "Recognizer/Types.h"
#include "Recognizer/Recognizer.h"
#include "Recognizer/BlinkBarcode/BarcodeData.h"

#ifdef __cplusplus
extern "C"
{
#endif

struct MBBarcodeRecognizerSettings;

/**
 * @brief Typedef for MBBarcodeRecognizerSettings structure.
 */
MB_EXPORTED_TYPE typedef struct MBBarcodeRecognizerSettings MBBarcodeRecognizerSettings;

/**
 * @memberof MBBarcodeRecognizerSettings
 * @brief Populate MBBarcodeRecognizerSettings structure with default values.
 * @return Nothing
 */
MB_API void MB_CALL barcodeRecognizerSettingsInit( MBBarcodeRecognizerSettings * );

/**
 * @struct MBBarcodeRecognizerSettings
 * @brief Settings for configuring MBBarcodeRecognizer.
 */
struct MBBarcodeRecognizerSettings
{
    /**
     * Enables scanning of barcodes with inverse intensity values (e.g. white barcode on black background)
     */
    MBBool shouldScanInverse;
    /**
     * Use this flag to use more processing time for barcode detection and decoding. With this flag enabled, better recognition quality can be expected.
     */
    MBBool slowerThoroughScan;
    /**
     * Allow enabling the autodetection of image scale when scanning barcodes. Enabling this can improve recognition
     * quality of high resolution images, at the cost of additional processing time.
     */
    MBBool useAutoScale;

    /**
     * Allow scanning PDF417 barcodes which don't have quiet zone surrounding it (e.g. text
     * concatenated with barcode). This option can drastically increase recognition time and
     * can even reduce the recognition quality of barcodes that do have quiet zone
     * surrounding it. This option is ignored if PDF417 barcode scanning is not enabled.
     */
    MBBool nullQuietZoneAllowed;

    /**
     * Allow scanning of uncertain PDF417 barcodes. Uncertain scanning refers to returning result even on barcodes
     * which checksum does not match. Ideal for incomplete or damaged barcodes. This option is ignored if
     * PDF417 barcode scanning is not enabled.
     */
    MBBool shouldScanUncertain;

    /**
     * When returning Code39 barcode scanning result, interpret it as Code39 extended data encoding.
     * This option is ignored if Code39 barcode scanning is not enabled.
     */
    MBBool readCode39AsExtendedData;

    /**
     * Use this flag to enable reading of Aztec 2D barcodes.
     */
    MBBool scanAztec;

    /**
     * Use this flag to enable reading of Code 128 1D barcodes.
     */
    MBBool scanCode128;

    /**
     * Use this flag to enable reading of Code 39 1D barcodes.
     */
    MBBool scanCode39;

    /**
     * Use this flag to enable reading of DataMatrix 2D barcodes.
     */
    MBBool scanDataMatrix;

    /**
     * Use this flag to enable reading of EAN 13 1D barcodes.
     */
    MBBool scanEAN13;

    /**
     * Use this flag to enable reading of EAN 8 1D barcodes.
     */
    MBBool scanEAN8;

    /**
     * Use this flag to enable reading of ITF 1D barcodes.
     */
    MBBool scanITF;

    /**
     * Use this flag to enable reading of PDF417 2D barcodes.
     */
    MBBool scanPDF417;

    /**
     * Use this flag to enable reading of QR codes.
     */
    MBBool scanQRCode;

    /**
     * Use this flag to enable reading of UPC A 1D barcodes.
     */
    MBBool scanUPCA;

    /**
     * Use this flag to enable reading of UPC E 1D barcodes.
     */
    MBBool scanUPCE;

#ifdef __cplusplus
    /** Default constructor for c++ */
    MBBarcodeRecognizerSettings()
    {
        barcodeRecognizerSettingsInit( this );
    }
#endif
};

/**
 * @struct MBBarcodeRecognizerResult
 * @brief A result that can be obtained from MBBarcodeRecognizer.
 */
struct MBBarcodeRecognizerResult
{
    /** Base result common to all recognizer results. */
    MBBaseRecognizerResult baseResult;

    /** This structure contains all scanned data from the barcode */
    MBBarcodeData barcodeData;
};

/**
 * @brief Typedef for the MBBarcodeRecognizerResult structure.
 */
MB_EXPORTED_TYPE typedef struct MBBarcodeRecognizerResult MBBarcodeRecognizerResult;

/**
 * @struct MBBarcodeRecognizer
 * @brief A recognizer that can scan barcodes.
 */
struct MBBarcodeRecognizer;

/**
 * @brief Typedef for the MBBarcodeRecognizer structure.
 */
MB_EXPORTED_TYPE typedef struct MBBarcodeRecognizer MBBarcodeRecognizer;

/**
 * @memberof MBBarcodeRecognizer
 * @brief Allocates and initializes new MBBarcodeRecognizer object.
 * @param barcodeRecognizer Pointer to pointer referencing the created MBBarcodeRecognizer object.
 * @param barcodeRecognizerSettings Settings that will be used for creating of the MBBarcodeRecognizer object.
 * @return status of the operation. The operation may fail (i.e. if license key is not set or does not allow
 *         usage of the requested recognizer), so please check the returned status for possible errors.
 */
MB_API MBRecognizerErrorStatus MB_CALL barcodeRecognizerCreate( MBBarcodeRecognizer ** barcodeRecognizer, MBBarcodeRecognizerSettings const * barcodeRecognizerSettings );

/**
 * @memberof MBBarcodeRecognizer
 * @brief Updates the MBBarcodeRecognizer with the new settings.
 * Note that updating the recognizer while it is being in use by MBRecognizerRunner will fail.
 * @param barcodeRecognizer MBBarcodeRecognizer that should be updated with new settings.
 * @param barcodeRecognizerSettings Settings that will be used for updating the MBBarcodeRecognizer object.
 * @return status of the operation. The operation may fail (i.e. if recognizer is in use by the MBRecognizerRunner),
 *         so please check the returned status for possible errors.
 */
MB_API MBRecognizerErrorStatus MB_CALL barcodeRecognizerUpdate( MBBarcodeRecognizer * barcodeRecognizer, MBBarcodeRecognizerSettings const * barcodeRecognizerSettings );

/**
 * @memberof MBBarcodeRecognizer
 * @brief Obtains the result from the given MBBarcodeRecognizer object.
 * @param result MBBarcodeRecognizerResult structure that will be filled with the recognized data.
 * Note that all pointers in structure will remain valid until given recognizer is
 * destroyed with barcodeRecognizerDelete function or is used for performing the new recognition.
 * @param barcodeRecognizer MBBarcodeRecognizer from which result should be obtained.
 * @return status of the operation.
 */
MB_API MBRecognizerErrorStatus MB_CALL barcodeRecognizerResult( MBBarcodeRecognizerResult * result, MBBarcodeRecognizer const * barcodeRecognizer );

/**
 * @memberof MBBarcodeRecognizer
 * @brief Destroys the given MBBarcodeRecognizer.
 * @param barcodeRecognizer Pointer to pointer to MBBarcodeRecognizer structure that needs to be destroyed.
 * After destruction, the pointer to MBBarcodeRecognizer structure will be set to NULL.
 * @return status of the operation
 */
MB_API MBRecognizerErrorStatus MB_CALL barcodeRecognizerDelete( MBBarcodeRecognizer ** barcodeRecognizer );

#ifdef __cplusplus
}
#endif

#endif
