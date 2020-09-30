/**
 * @file RecognizerError.h
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

#ifndef RECOGNIZERERROR_H_
#define RECOGNIZERERROR_H_

#include "Export.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 @enum MBRecognizerErrorStatus
 @brief Enumeration of all possible error statuses
 */
enum MBRecognizerErrorStatus {
    /** Operation was successfully completed */
    RECOGNIZER_ERROR_STATUS_SUCCESS = 0,

    /** Operation failed */
    RECOGNIZER_ERROR_STATUS_FAIL,

    /** Failed to allocate memory */
    RECOGNIZER_ERROR_STATUS_MALLOC_FAIL,

    /** Invalid or expired license key was provided */
    RECOGNIZER_ERROR_STATUS_INVALID_LICENSE_KEY,

    /** Operation is not supported */
    RECOGNIZER_ERROR_STATUS_NOT_SUPPORTED,

    /** Specified recognizer is in use and cannot be modified. */
    RECOGNIZER_ERROR_STATUS_RECOGNIZER_IN_USE,

    /** Invalid settings were provided */
    RECOGNIZER_ERROR_STATUS_INVALID_SETTINGS,

    /** Invalid argument was provided to the function */
    RECOGNIZER_ERROR_STATUS_INVALID_ARGUMENT,

    /** There has been a network error while validating the license key */
    RECOGNIZER_ERROR_STATUS_NETWORK_ERROR,

    /** Given license key has been remotely locked */
    RECOGNIZER_ERROR_STATUS_REMOTE_LOCK
};

/**
 * @brief Typedef for RecognizerErrorStatus enum.
 */
typedef MB_EXPORTED_TYPE enum MBRecognizerErrorStatus MBRecognizerErrorStatus;

/**
 Helper method for fetching string representation of the error status. Usually used in debugging.

 @param errorStatus   status for which the string representation is required
 @return null terminated string for required status
 */
MB_API char const * MB_CALL recognizerErrorToString( MBRecognizerErrorStatus errorStatus );

#ifdef __cplusplus
}
#endif

#endif
