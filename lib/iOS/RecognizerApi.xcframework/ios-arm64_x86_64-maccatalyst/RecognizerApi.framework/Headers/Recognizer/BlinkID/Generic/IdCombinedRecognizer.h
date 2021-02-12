/**
* @file IdCombinedRecognizer.h
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
#ifndef COMBINEDIDRECOGNIZER_H_INCLUDED
#define COMBINEDIDRECOGNIZER_H_INCLUDED

#include <Recognizer/BlinkID/DataMatchResult.h>
#include <Recognizer/BlinkID/DigitalSignatureResult.h>
#include <Recognizer/BlinkID/Generic/Common/BarcodeResult.h>
#include <Recognizer/BlinkID/Generic/Common/ImageAnalysisResult.h>
#include <Recognizer/BlinkID/Generic/Common/ImageResult.h>
#include <Recognizer/BlinkID/Generic/Common/ProcessingStatus.h>
#include <Recognizer/BlinkID/Generic/Common/VIZResult.h>
#include <Recognizer/BlinkID/Generic/IdRecognizer.h>
#include <Recognizer/BlinkID/MRTD/MRZResult.h>
#include <Recognizer/Export.h>
#include <Recognizer/RecognizerError.h>
#include <Recognizer/Types.h>
#include <Utils/Date.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct MBBlinkIdCombinedRecognizerSettings;

/**
 * @brief Typedef for the MBBlinkIdCombinedRecognizerSettings structure.
 */
MB_EXPORTED_TYPE typedef struct MBBlinkIdCombinedRecognizerSettings MBBlinkIdCombinedRecognizerSettings;

/**
 * @memberof MBBlinkIdCombinedRecognizerSettings
 * @brief Populate MBBlinkIdCombinedRecognizerSettings structure with default values.
 * @return Nothing
 */
MB_API void MB_CALL blinkIdCombinedRecognizerSettingsDefaultInit( MBBlinkIdCombinedRecognizerSettings * );

/**
 * @struct MBBlinkIdCombinedRecognizerSettings
 * @brief Settings for configuring MBBlinkIdCombinedRecognizer
 */
struct MBBlinkIdCombinedRecognizerSettings
{
    /** All settings as for MBBlinkIdRecognizer */
    MBBlinkIdRecognizerSettings baseSettings;

    /** Whether or not recognition result should be signed. */
    MBBool allowSignature;

    /** Skip back side capture and processing step when back side of the document is not supported. */
    MBBool skipUnsupportedBack;

#ifdef __cplusplus
    MBBlinkIdCombinedRecognizerSettings()
    {
        blinkIdCombinedRecognizerSettingsDefaultInit( this );
    }
#endif
};

/**
 * @struct MBBlinkIdCombinedRecognizerResult
 * @brief Result of the BlinkIDCombinedRecognizer
 */
struct MBBlinkIdCombinedRecognizerResult
{
    /** Fields common to both BlinkIdRecognizer and BlinkIdCombinedRecognizer */
    MBBlinkIdRecognizerCommonResult common;

    /** The data extracted from the front side visual inspection zone. */
    MBVIZResult frontViz;

    /** The data extracted from the back side visual inspection zone. */
    MBVIZResult backViz;

    /** Image of the scanned document's front side. */
    MBImageResult fullDocumentFrontImage;

    /** Image of the scanned document's back side. */
    MBImageResult fullDocumentBackImage;

    /** Various information obtained by analysing the scanned front side image. */
    MBImageAnalysisResult frontImageAnalysisResult;

    /** Various information obtained by analysing the scanned back side image. */
    MBImageAnalysisResult backImageAnalysisResult;

    /** Specifies a digital signature of the specific recognizer result. */
    MBDataMatchResult dataMatch;

    /** Indicates if the first side is done scanning. */
    MBBool scanningFirstSideDone;

    /** Contains the digital signature */
    MBDigitalSignatureResult digitalSignature;
};

/**
 * @brief Typedef for the MBBlinkIdCombinedRecognizerResult structure.
 */
MB_EXPORTED_TYPE typedef struct MBBlinkIdCombinedRecognizerResult MBBlinkIdCombinedRecognizerResult;

/**
 * @struct MBBlinkIdCombinedRecognizer
 * @brief A recognizer that can scan and parse identity cards
 */
struct MBBlinkIdCombinedRecognizer;

/**
 * @brief Typedef for the MBBlinkIdCombinedRecognizer structure.
 */
typedef struct MBBlinkIdCombinedRecognizer MBBlinkIdCombinedRecognizer;


/**
 * @memberof MBBlinkIdCombinedRecognizer
 * @brief Allocates and initializes new BlinkIDCombinedRecognizer object.
 * @param blinkIdCombinedRecognizer Pointer to pointer referencing the created BlinkIDCombinedRecognizer object.
 * @param blinkIdCombinedRecognizerSettings Settings that will be used for creating of the BlinkIDCombinedRecognizer object.
 * @return status of the operation. The operation may fail (i.e. if license key is not set or does not allow
 *         usage of the requested recognizer), so please check the returned status for possible errors.
 */
MB_API MBRecognizerErrorStatus MB_CALL blinkIdCombinedRecognizerCreate( MBBlinkIdCombinedRecognizer ** blinkIdCombinedRecognizer, MBBlinkIdCombinedRecognizerSettings const * blinkIdCombinedRecognizerSettings );

/**
 * @memberof MBBlinkIdCombinedRecognizer
 * @brief Updates the BlinkIDCombinedRecognizer with the new settings.
 * Note that updating the recognizer while it is being in use by MBRecognizerRunner will fail.
 * @param blinkIdCombinedRecognizer BlinkIDCombinedRecognizer that should be updated with new settings.
 * @param blinkIdCombinedRecognizerSettings Settings that will be used for updating the BlinkIDCombinedRecognizer object.
 * @return status of the operation. The operation may fail (i.e. if recognizer is in use by the MBRecognizerRunner),
 *         so please check the returned status for possible errors.
 */
MB_API MBRecognizerErrorStatus MB_CALL blinkIdCombinedRecognizerUpdate( MBBlinkIdCombinedRecognizer * blinkIdCombinedRecognizer, MBBlinkIdCombinedRecognizerSettings const * blinkIdCombinedRecognizerSettings );

/**
 * @memberof MBBlinkIdCombinedRecognizer
 * @brief Obtains the result from the given BlinkIDCombinedRecognizer object.
 * @param result BlinkIDCombinedRecognizerResult structure that will be filled with the recognized data.
 * Note that all pointers in structure will remain valid until given recognizer is
 * destroyed with blinkIdCombinedRecognizerDelete function or is used for performing the new recognition.
 * @param blinkIdCombinedRecognizer BlinkIDCombinedRecognizer from which result should be obtained.
 * @return status of the operation.
 */
MB_API MBRecognizerErrorStatus MB_CALL blinkIdCombinedRecognizerResult( MBBlinkIdCombinedRecognizerResult * result, MBBlinkIdCombinedRecognizer const * blinkIdCombinedRecognizer );

/**
 * @memberof MBBlinkIdCombinedRecognizer
 * @brief Destroys the given BlinkIDCombinedRecognizer.
 * @param blinkIdCombinedRecognizer Pointer to pointer to BlinkIDCombinedRecognizer structure that needs to be destroyed.
 * After destruction, the pointer to BlinkIDCombinedRecognizer structure will be set to NULL.
 * @return status of the operation
 */
MB_API MBRecognizerErrorStatus MB_CALL blinkIdCombinedRecognizerDelete( MBBlinkIdCombinedRecognizer ** blinkIdCombinedRecognizer );

#ifdef __cplusplus
}
#endif

#endif
