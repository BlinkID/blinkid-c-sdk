/**
 * @file Licensing.h
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

#ifndef LICENSING_H_INCLUDED
#define LICENSING_H_INCLUDED

#include "Export.h"
#include "RecognizerError.h"
#include "Types.h"

#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Unlocks the SDK with given license key encoded as base64 string.
 * NOTE: This function is not thread safe.
 * @param licenseKeyBase64 License key as base64 encoded string bound to current
 *                         package name/bundle id which will be used for unlocking.
 * @return status of the operation
 */
MB_API MBRecognizerErrorStatus MB_CALL recognizerAPIUnlockWithLicenseKey( char const * licenseKeyBase64 );

/**
 * @brief Unlocks the SDK with given license key presented as raw buffer.
 * NOTE: This function is not thread safe.
 * @param licenseBuffer Buffer containing the entire license file.
 * @param licenseBufferLength Length of licenseBuffer
 * @return status of the operation.
 */
MB_API MBRecognizerErrorStatus MB_CALL recognizerAPIUnlockWithLicenseBuffer( MBByte const * licenseBuffer, size_t licenseBufferLength );

/**
 * @brief Unlocks the SDK with given license key encoded as base64 string.
 * NOTE: This function is not thread safe.
 * @param licenseKeyBase64 License key as base64 encoded string bound to given
 *                         licensee which allows usage inside multiple applications.
 * @param licensee   Licensee to which license key is bound.
 * @return status of the operation
 */
MB_API MBRecognizerErrorStatus MB_CALL recognizerAPIUnlockForLicenseeWithLicenseKey( char const * licenseKeyBase64, char const * licensee );

/**
 * @brief Unlocks the SDK with given license key presented as raw buffer.
 * NOTE: This function is not thread safe.
 * @param licenseBuffer Buffer containing the entire license file.
 * @param licenseBufferLength Length of licenseBuffer.
 * @param licensee Licensee to which license key is bound.
 * @return status of the operation
 */
MB_API MBRecognizerErrorStatus MB_CALL recognizerAPIUnlockForLicenseeWithLicenseBuffer( MBByte const * licenseBuffer, size_t licenseBufferLength, char const * licensee );

#ifdef __cplusplus
}
#endif

#endif
