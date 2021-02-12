/**
 * @file RecognizerImage.h
 *
 * Copyright (c)2015 MicroBlink Ltd. All rights reserved.
 *
 * ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
 * OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
 * WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
 * UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
 * THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
 * REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.
 */

#ifndef RECOGNIZERIMAGE_HPP
#define RECOGNIZERIMAGE_HPP

#include "Export.h"
#include "RecognizerError.h"
#include "Types.h"

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
  @struct MBRecognizerImage
  @brief MBRecognizerImage data structure. Holds image on which recognition will bw performed.
  */
struct MBRecognizerImage;

/**
 * @brief Typedef for MBRecognizerImage structure.
 */
typedef MB_EXPORTED_TYPE struct MBRecognizerImage MBRecognizerImage;

/**
 * @enum MBRawImageType
 * @brief Enumeration of all possible raw image types
 */
enum MBRawImageType {

    /** 4 channel raw image with 32 bit per pixel, 8 bit per channel, channel order is BGRA */
    MB_RAW_IMAGE_TYPE_BGRA,

    /** 4 channel raw image with 32 bit per pixel, 8 bit per channel, channel order is RGBA */
    MB_RAW_IMAGE_TYPE_RGBA,

    /** 3 channel raw image with 24 bit per pixel, 8 bit per channel, channel order is BGR */
    MB_RAW_IMAGE_TYPE_BGR,

    /** 3 channel raw image with 24 bit per pixel, 8 bit per channel, channel order is BGR */
    MB_RAW_IMAGE_TYPE_RGB,

    /** 1 channel grayscale raw image with 8 bit per pixel */
    MB_RAW_IMAGE_TYPE_GRAY,

    /**
     Raw YUV 4:2:0 image with a plane of 8 bit Y samples followed by an interleaved
     V/U plane containing 8 bit 2x2 subsampled chroma samples. Typically, frames from Android
     video capture are obtained in this format.
     */
    MB_RAW_IMAGE_TYPE_NV21

};

/**
 * @brief Typedef for MBRawImageType enum.
 */
typedef MB_EXPORTED_TYPE enum MBRawImageType MBRawImageType;

/**
 * @enum MBImageOrientation
 * @brief Specifies the orientation of the contents of the image.
 * This is important for some recognizers, especially when
 * performing recognition on the mobile device.
 */
enum MBImageOrientation
{
    /**
     * Image contents are rotated 90 degrees left.
     * This usually happens on mobile devices when capturing image while
     * device is held in "portrait" orientation, while device camera sensor
     * is mounted horizontally (i.e. produced image is in "landscape" orienation).
     */
    MB_IMAGE_ORIENTATION_ROTATED_LEFT_90,

    /**
     * Image contents are not rotated in any manner.
     * This orientation usually happens on mobile devices when capturing
     * image while device is held in "landscape" orientation, while device
     * camera sensor is mounted horizontally (i.e. also in same orientation).
     */
    MB_IMAGE_ORIENTATION_NO_ROTATION,

    /**
     * Image contents are rotated 90 degrees right.
     * This usually happens on mobile devices when capturing image while
     * device is held in "reverse-portrait" orientation, while device camera sensor
     * is mounted horizontally (i.e. produced image is in "landscape" orienation).
     */
    MB_IMAGE_ORIENTATION_ROTATED_RIGHT_90,

    /**
     * Image contents are rotated 180 degrees, i.e. image contents are "upside down".
     * This usually happens on mobile devices when capturing image while
     * device is held in "reverse-landscape" orientation, while device camera sensor
     * is mounted horizontally (i.e. produced image is in "landscape" orienation).
     */
    MB_IMAGE_ORIENTATION_ROTATED_180
};

/**
 * @brief Typedef for MBImageOrientation enum.
 */
typedef MB_EXPORTED_TYPE enum MBImageOrientation MBImageOrientation;

/**
  @memberof MBRecognizerImage
  @brief Allocates and creates MBRecognizerImage object from raw image.
  Example:
  @code
    int image_width, image_height, image_stride;
    void* image_buffer;

    // populate above variables (i.e. by loading image file or capturing image with camera)

    MBRecognizerImage *image;
    MBRecognizerErrorStatus status = recognizerImageCreateFromRawImage(&img, image_buffer, image_width, image_height, image_stride, MB_RAW_IMAGE_TYPE_BGRA);
    // make sure last parameter correctly describes image format, otherwise a crash will occur later while processing the image. There is no way to
    // detect whether this parameter was given correctly while creating the image, so function may return MB_RECOGNIZER_ERROR_STATUS_SUCCESS even if
    // this parameter is wrong.

    if (status != MB_RECOGNIZER_ERROR_STATUS_SUCCESS) {
        const char* status_string = recognizerErrorToString(status);
        printf("CreateFromRawImage method returned status: %s\n", status_string);

        // handle error
    } else {
        // use MBRecognizerImage object
    }

    recognizerImageDelete(image);
  @endcode

  Raw image type is the type without any encoding. List of supported raw image types is given in enum MBRawImageType.
  @see MBRawImageType

  @param     image               Pointer to pointer referencing the created MBRecognizerImage object, set to NULL if error occured.
  @param     input               Pointer to a buffer with raw image pixels
  @param     width               Width of the image, in pixels
  @param     height              Height of the image, in pixels
  @param     bytesPerRow         Number of bytes contained in every row of the image
  @param     rawType             Type of the image. @see MBRawImageType
  @return    errorStatus         Status of the operation.
 */
MB_API MBRecognizerErrorStatus MB_CALL recognizerImageCreateFromRawImage( MBRecognizerImage** image, MBByte const * input, int width, int height, size_t bytesPerRow, MBRawImageType rawType );

/**
  @memberof MBRecognizerImage
  @brief Sets a new buffer to the given MBRecognizerImage.
  NOTE: This function will not make copy of the given buffer, so make sure that buffer stays alive and unchanged while
  this MBRecognizerImage is in use.
  Example:
  @code
    int image_width, image_height, image_stride;
    void* image_buffer;

    // populate above variables (i.e. by loading image file or capturing image with camera)

    MBRecognizerImage *image;

    // create image with recognizerImageCreateFromRawImage

    // now, update the image with new buffer
    MBRecognizerErrorStatus status = recognizerImageSetNewRawBuffer(img, image_buffer, image_width, image_height, image_stride, MB_RAW_IMAGE_TYPE_BGRA);
    // make sure last parameter correctly describes image format, otherwise a crash will occur later while processing the image. There is no way to
    // detect whether this parameter was given correctly while creating the image, so function may return MB_RECOGNIZER_ERROR_STATUS_SUCCESS even if
    // this parameter is wrong.

    if (status != MB_RECOGNIZER_ERROR_STATUS_SUCCESS) {
        const char* status_string = recognizerErrorToString(status);
        printf("CreateFromRawImage method returned status: %s\n", status_string);

        // handle error
    } else {
        // use MBRecognizerImage object
    }

    recognizerImageDelete(image);
  @endcode

  Raw image type is the type without any encoding. List of supported raw image types is given in enum MBRawImageType.
  @see MBRawImageType

  @param     image               Pointer referencing the created MBRecognizerImage object, must be non-NULL.
  @param     input               Pointer to a buffer with raw image pixels
  @param     width               Width of the image, in pixels
  @param     height              Height of the image, in pixels
  @param     bytesPerRow         Number of bytes contained in every row of the image
  @param     rawType             Type of the image. @see MBRawImageType
  @return    errorStatus         Status of the operation.
 */
MB_API MBRecognizerErrorStatus MB_CALL recognizerImageSetNewRawBuffer( MBRecognizerImage* image, MBByte const * input, int width, int height, size_t bytesPerRow, MBRawImageType rawType );

/**
 * @memberof MBRecognizerImage
 * @brief Allocates and creates MBRecognizerImage by copying another MBRecognizerImage. This method will copy pixel data, so it may be slow.
 * @param   image           Pointer to pointer referencing the created MBRecognizerImage object, set to NULL if error occured.
 * @param   original        Pointer to original MBRecognizerImage object that should be copied.
 * @return  errorStatus     Status of the operation.
 */
MB_API MBRecognizerErrorStatus MB_CALL recognizerImageCreateCopyFromImage( MBRecognizerImage** image, MBRecognizerImage const * original );

/**
  @memberof MBRecognizerImage
  @brief Deletes the image object and sets pointer to NULL

  @param    image           Double pointer to image object which is to be deleted.
  @return   errorStatus     Status of the operation.
 */
MB_API MBRecognizerErrorStatus MB_CALL recognizerImageDelete( MBRecognizerImage** image );

/**
 * @memberof MBRecognizerImage
 * @brief Sets the orientation of the image.
 * When created, each image has default orientation IMAGE_ORIENTATION_LANDSCAPE_RIGHT, which corresponds to 'natural' orientation of all images. However, if image was taken
 * in different orientation, you should set correct orientation with this method to ensure best recognition quality.
 * @param   image         Image to which orientation will be set.
 * @param   orientation   Orientation that will be set.
 * @return  errorStatus   Status of the operation.
 */
MB_API MBRecognizerErrorStatus MB_CALL recognizerImageSetImageOrientation( MBRecognizerImage * image, MBImageOrientation orientation );

/**
 * @memberof MBRecognizerImage
 * @brief Gets the orientation of the image.
 * @param   image         Image from which orientation will be obtained.
 * @return  Orientation of the image.
 */
MB_API MBImageOrientation MB_CALL recognizerImageGetImageOrientation( MBRecognizerImage const * image );

/**
 * @memberof MBRecognizerImage
 * @brief Gets buffer containing raw image bytes
 *
 * @param    image           Pointer to MBRecognizerImage object of interest.
 * @return   data            Buffer containing raw image bytes. You can use the obtained buffer until recognizerImageDelete
 *                           is called on the MBRecognizerImage object. If you want to use the buffer later, you must copy it.
 */
MB_API MBByte const * MB_CALL recognizerImageGetRawBytes( MBRecognizerImage const * image );

/**
 * @memberof MBRecognizerImage
 * @brief Gets modifiable buffer containing raw image bytes
 *
 * @param    image           Pointer to MBRecognizerImage object of interest.
 * @return   data            Modifiable buffer containing raw image bytes. You can use the obtained buffer until recognizerImageDelete
 *                           is called on the MBRecognizerImage object. If you want to use the buffer later, you must copy it.
 */
MB_API MBByte * MB_CALL recognizerImageGetMutableRawBytes( MBRecognizerImage * image );

/**
  @memberof MBRecognizerImage
  @brief Gets width of image in number of pixels

  @param    image           Pointer to MBRecognizerImage object of interest.
  @return   width of image in pixels
  */
MB_API int MB_CALL recognizerImageGetWidth( MBRecognizerImage const * image );

/**
  @memberof MBRecognizerImage
  @brief Gets height of image in number of pixels

  @param    image           Pointer to MBRecognizerImage object of interest.
  @return   height of image in pixels
  */
MB_API int MB_CALL recognizerImageGetHeight( MBRecognizerImage const * image );

/**
  @memberof MBRecognizerImage
  @brief Gets bytes per row for given image

  @param    image           Pointer to MBRecognizerImage object of interest.
  @return   bytes per row in image
  */
MB_API int MB_CALL recognizerImageGetBytesPerRow( MBRecognizerImage const * image );

/**
  @memberof MBRecognizerImage
  @brief Gets raw image type for given image

  @param    image           Pointer to MBRecognizerImage object of interest.
  @return   raw image type of image
  */
MB_API MBRawImageType MB_CALL recognizerImageGetRawImageType( MBRecognizerImage const * image );

#ifdef __cplusplus
}
#endif

#endif
