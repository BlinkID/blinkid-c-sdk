/**
* @file ImageAnalysisDetectionStatus.h
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
#ifndef IMAGE_ANALYSIS_DETECTION_STATUS_H_INCLUDED
#define IMAGE_ANALYSIS_DETECTION_STATUS_H_INCLUDED

#include <Recognizer/Export.h>

/**
*  ImageAnalysisDetectionResult enum defines possible states of detection.
*/
enum MBImageAnalysisDetectionStatus
{
    /** Detection was not performed */
    MB_IMAGE_ANALYSIS_DETECTION_STATUS_NOT_AVAILABLE = 0,

    /** Not detected on input image */
    MB_IMAGE_ANALYSIS_DETECTION_STATUS_NOT_DETECTED,

    /* Detected on input image */
    MB_IMAGE_ANALYSIS_DETECTION_STATUS_DETECTED
};

/**
* @brief Typedef for MBImageAnalysisDetectionStatus enum.
*/
MB_EXPORTED_TYPE typedef enum MBImageAnalysisDetectionStatus MBImageAnalysisDetectionStatus;

#endif
