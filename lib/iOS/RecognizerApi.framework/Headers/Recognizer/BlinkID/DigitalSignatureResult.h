/**
* @file DigitalSignatureResult.h
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
#ifndef DIGITALSIGNATURERESULT_H_INCLUDED
#define DIGITALSIGNATURERESULT_H_INCLUDED

#include <Recognizer/Export.h>

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Specifies a digital signature of the specific recognizer result.
 */
struct MBDigitalSignatureResult
{
    /** Version of the digital signature. */
    uint32_t version;

    /** The digital signature of the recognition results */
    uint8_t  signature[ 64 ];
};

/**
 * @brief Typedef for the MBDigitalSignatureResult structure.
 */
MB_EXPORTED_TYPE typedef struct MBDigitalSignatureResult MBDigitalSignatureResult;

#ifdef __cplusplus
}
#endif

#endif
