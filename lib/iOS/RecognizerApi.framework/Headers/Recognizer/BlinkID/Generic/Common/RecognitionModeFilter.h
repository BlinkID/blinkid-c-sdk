/**
* @file RecognitionModeFilter.h
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
#ifndef RECOGNITION_MODE_FILTER_H_INCLUDED
#define RECOGNITION_MODE_FILTER_H_INCLUDED

#include <Recognizer/Types.h>
#include <Recognizer/Export.h>

/**
* RecognitionModeFilter is used to enable/disable recognition of specific document groups.
* Setting is taken into account only if the right for that document is purchased.
*/
struct MBRecognitionModeFilter
{
    /** Enable scanning of MRZ IDs. Setting is taken into account only if the mrz_id right is purchased. */
    MBBool enableMrzId;

    /** Enable scanning of visa MRZ. Setting is taken into account only if the visa right is purchased. */
    MBBool enableMrzVisa;

    /** Enable scanning of Passport MRZ. Setting is taken into account only if the passport right is purchased. */
    MBBool enableMrzPassport;

    /** Enable scanning of Photo ID. Setting is taken into account only if the photo_id right is purchased. */
    MBBool enablePhotoId;

    /** Enable full document recognition. Setting is taken into account only if the document right to scan that document is purchased. */
    MBBool enableFullDocumentRecognition;
};

/**
* @brief Typedef for MBRecognitionModeFilter struct.
*/
MB_EXPORTED_TYPE typedef struct MBRecognitionModeFilter MBRecognitionModeFilter;

#endif
