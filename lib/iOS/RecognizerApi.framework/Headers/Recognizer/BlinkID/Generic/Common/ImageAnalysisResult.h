/**
* @file ImageAnalysisResult.h
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
#ifndef UTILS_IMAGE_ANALYSIS_RESULT_H_INCLUDED
#define UTILS_IMAGE_ANALYSIS_RESULT_H_INCLUDED

#include <Recognizer/BlinkID/Generic/Common/DocumentImageColorStatus.h>
#include <Recognizer/BlinkID/Generic/Common/ImageAnalysisDetectionStatus.h>
#include <Recognizer/Export.h>
#include <Recognizer/Types.h>

/**
 * Result of the image analysis.
 * Includes color status, Moire status and blurred.
 */
struct MBImageAnalysisResult
{
    /** Whether the image is blurred. */
    MBBool blurred;

    /** The color status determined from scanned image. */
    MBDocumentImageColorStatus documentImageColorStatus;

    /** The Moire pattern detection status determined from the scanned image. */
    MBImageAnalysisDetectionStatus documentImageMoireStatus;

    /** Face detection status determined from the scanned image. */
    MBImageAnalysisDetectionStatus faceDetectionStatus;

    /** Mrz detection status determined from the scanned image. */
    MBImageAnalysisDetectionStatus mrzDetectionStatus;

    /** Barcode detection status determined from the scanned image. */
    MBImageAnalysisDetectionStatus barcodeDetectionStatus;
};

/**
* @brief Typedef for MBImageAnalysisDetectionStatus struct.
*/
MB_EXPORTED_TYPE typedef struct MBImageAnalysisResult MBImageAnalysisResult;

#endif
