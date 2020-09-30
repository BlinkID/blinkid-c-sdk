/**
* @file RecognizerApiUtils.h
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

#ifndef RECOGNIZERAPIUTILS_H_
#define RECOGNIZERAPIUTILS_H_

#include "RecognizerError.h"

#ifdef __ANDROID__
#include "jni.h"
#endif

#ifdef __APPLE__
#   include <TargetConditionals.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Returns the library version string.
 * @returns library version string
 */
MB_API char const * MB_CALL recognizerAPIGetVersionString();

/**
 * @brief Sets the location where required resources will be loaded from.
 * If not set, "res" folder within current working directory will be used.
 * NOTE: It is safe to call this with temporary pointer, as internal a copy will be made to store the given string.
 * @param resourcePath path to resource folder
 * @returns status of the operation
 */
MB_API MBRecognizerErrorStatus MB_CALL recognizerAPISetResourcesLocation( char const * resourcePath );

#if !defined( __ANDROID__ ) && !( defined( __APPLE__ ) && TARGET_OS_IPHONE )
/**
 * @brief Sets the location where cache files will be stored on desktop platforms.
 * The given folder may or may not be used, depending on the nature of used license key.
 * The files that may need to be stored are:
 *      - the state of the license counters (number of scans since last report to the server)
 *      - cached server permission for licenses that require online validation
 * If offline license is used, this folder will not be used as no caching is required.
 * If not set, the user's home folder will be used for storing files.
 * If given path to non-existing folder, RECOGNIZER_ERROR_STATUS_INVALID_ARGUMENT will be returned and
 * the user's home folder will be used for storing files.
 * If given path is not writeable, RECOGNIZER_ERROR_STATUS_INVALID_ARGUMENT will be returned and
 * the user's home folder will be used for storing files.
 * It is recommended to set this to unique path for your application on desktop systems, in order to avoid clashes
 * with other applications on the system that use the same SDK.
 * This function is not available on mobile systems (iOS and Android), as every application on those systems
 * is already isolated from all other apps.
 * @param cacheFolder Location of the folder where cache files will be stored.
 * @return status of the operation. If given path is not folder or not writeable,
 *         RECOGNIZER_ERROR_STATUS_INVALID_ARGUMENT is returned.
 */
MB_API MBRecognizerErrorStatus MB_CALL recognizerAPISetCacheLocation( char const * cacheFolder );
#endif

#ifdef __ANDROID__
/**
 * @brief Sets the JNI application context to the SDK.
 * This is required in order for SDK to be able to load resources from assets and use other Android Java APIs.
 * @param env JNI environment pointer, as given by any JNI entry function.
 * @param applicationContext Local reference to instance of android.content.Context. It is recommended to use application context
 *                           to avoid memory leaks as the context will be retained in the SDK indefinitely. For more information
 *                           about application contexts vs activity contexts with respect to memory leaks, please see
 *                           https://android-developers.googleblog.com/2009/01/avoiding-memory-leaks.html
 * @returns Nothing.
 */
MB_API void MB_CALL recognizerAPIInitializeAndroidApplication( JNIEnv * env, jobject applicationContext );
#endif


#ifdef __cplusplus
}
#endif

#endif
