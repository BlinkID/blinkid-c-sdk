/**
 * @file ExtensionFactors.h
 *
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

#ifndef EXTENSION_FACTORS_H_INCLUDED
#define EXTENSION_FACTORS_H_INCLUDED

#include <Recognizer/Export.h>
#include <Recognizer/Types.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct MBExtensionFactors;

/**
 * @brief Typedef for the MBExtensionFactors structure.
 */
MB_EXPORTED_TYPE typedef struct MBExtensionFactors MBExtensionFactors;

/**
 * @memberof MBExtensionFactors
 * @brief Populate MBExtensionFactors structure with default values.
 * @return Nothing
 */
MB_API void MB_CALL extensionFactorsDefaultInit( MBExtensionFactors * );

/**
 * Extension factors relative to corresponding dimension of the full image. For example,
 * {@code upFactor} and {@code downFactor} define extensions relative to image height, e.g.
 * when {@code upFactor} is 0.5, upper image boundary will be extended for half of image's full
 * height.
 * @code
 *                      ._______________________________________.
 *                      |                   ↑                   |
 *                      |                upFactor               |
 *   .________.         |              .________.               |
 *   |        |   -->   |  ⃖ leftFactor |        | rightFactor  ⃗ |
 *   |________|         |              |________|               |
 *                      |                   ↓                   |
 *                      |               downFactor              |
 *                      |_______________________________________|
 * @endcode
 */
struct MBExtensionFactors
{
    /** Currently used image extension factor relative to full image height in UP direction. */
    float upFactor;

    /** Currently used image extension factor relative to full image height in DOWN direction. */
    float downFactor;

    /** Currently used image extension factor relative to full image height in LEFT direction. */
    float leftFactor;

    /** Currently used image extension factor relative to full image height in RIGHT direction. */
    float rightFactor;

#ifdef __cplusplus
    MBExtensionFactors()
    {
        extensionFactorsDefaultInit( this );
    }
#endif
};

#ifdef __cplusplus
}
#endif

#endif
