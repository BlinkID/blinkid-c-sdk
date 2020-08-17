/**
 * @file Rectangle.h
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
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Export.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @struct MBRectangle
  * @brief This structure represents the rectangle.
  */
struct MBRectangle {
    /** horizontal position of the rectangle */
    float x;
    /** vertical position of the rectangle */
    float y;
    /** width of the rectangle */
    float width;
    /** height of the rectangle */
    float height;
};

/**
 * @brief Typedef for MBRectangle structure.
 */
typedef MB_EXPORTED_TYPE struct MBRectangle MBRectangle;

#ifdef __cplusplus
}
#endif

#endif
