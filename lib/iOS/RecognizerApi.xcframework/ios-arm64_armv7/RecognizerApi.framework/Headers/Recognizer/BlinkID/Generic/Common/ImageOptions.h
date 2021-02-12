/**
* @file ImageOptions.h

*  Created on: 15.09.2020.
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

#ifndef IMAGE_OPTIONS_INCLUDED
#define IMAGE_OPTIONS_INCLUDED

#include <Recognizer/BlinkID/Generic/Common/ExtensionFactors.h>
#include <Recognizer/Export.h>
#include <Recognizer/Types.h>

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct MBImageOptions;

/**
 * @brief Typedef for the MBImageOptions structure.
 */
MB_EXPORTED_TYPE typedef struct MBImageOptions MBImageOptions;

/**
 * @memberof MBImageOptions
 * @brief Populate MBImageOptions structure with default values.
 * @return Nothing
 */
MB_API void MB_CALL imageOptionsDefaultInit( MBImageOptions * );

/**
 * Options for all images.
 */
struct MBImageOptions
{
    /** If only raw image is needed. */
    MBBool returnRawImage;
    /** If only encoded image is needed. */
    MBBool returnEncodedImage;
    /** The image DPI. */
    uint16_t imageDpi;

#ifdef __cplusplus
    MBImageOptions()
    {
        imageOptionsDefaultInit( this );
    }
#endif
};

struct MBFullDocumentImageOptions;

/**
 * @brief Typedef for the MBFullDocumentImageOptions structure.
 */
MB_EXPORTED_TYPE typedef struct MBFullDocumentImageOptions MBFullDocumentImageOptions;

/**
 * @memberof MBFullDocumentImageOptions
 * @brief Populate MBFullDocumentImageOptions structure with default values.
 * @return Nothing
 */
MB_API void MB_CALL fullDocumentImageOptionsDefaultInit( MBFullDocumentImageOptions * );

/**
 * Options for all images.
 */
struct MBFullDocumentImageOptions
{
    /** Image options all images have. */
    MBImageOptions imageOptions;

    /** Extension factors for the image around the full document image. */
    MBExtensionFactors extensionFactors;

#ifdef __cplusplus
    MBFullDocumentImageOptions()
    {
        fullDocumentImageOptionsDefaultInit( this );
    }
#endif
};


#ifdef __cplusplus
}
#endif

#endif
