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

#ifdef __cplusplus
extern "C" {
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
