/**
 *  @file ImageResult.h
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

#ifndef MBIMAGERESULT_H_INCLUDED
#define MBIMAGERESULT_H_INCLUDED

#include <Recognizer/RecognizerImage.h>
#include <Recognizer/RecognizerRunner.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct MBRawImage
 * @brief Image structure which holds a raw image.
 */
struct MBRawImage
{
    /** Structure containing width and height of the image. */
    MBSize size;

    /** Data of the image. */
    unsigned char const * data;

    /** Type of the image. */
    MBRawImageType imageType;

    /** Orientation of the image. */
    MBImageOrientation orientation;
};

/**
 * @brief Typedef for the MBRawImage structure.
 */
MB_EXPORTED_TYPE typedef struct MBRawImage MBRawImage;

/**
 * @struct MBEncodedImage
 * @brief Image structure which holds an encoded image.
 */
struct MBEncodedImage
{
    /** Size of the data array. */
    size_t size;

    /** Data of the image. */
    unsigned char const * data;
};

/**
 * @brief Typedef for the MBEncodedImage structure.
 */
MB_EXPORTED_TYPE typedef struct MBEncodedImage MBEncodedImage;

/**
 * @struct MBImageResult
 * @brief Image structure which can hold a raw and an encoded image returned by recognizers.
 */
struct MBImageResult
{
    /** Raw image. */
    MBRawImage     rawImage;

    /** Encoded image. */
    MBEncodedImage encodedImage;
};

/**
 * @brief Typedef for the MBImageResult structure.
 */
MB_EXPORTED_TYPE typedef struct MBImageResult MBImageResult;

#ifdef __cplusplus
}
#endif

#endif
