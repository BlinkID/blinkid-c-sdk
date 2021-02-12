/**
 * @file IdRecognizer.h
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

#ifndef GENERICIDRECOGNIZER_H_INCLUDED
#define GENERICIDRECOGNIZER_H_INCLUDED

#include <Recognizer/BlinkID/Generic/Common/AnonymizationMode.h>
#include <Recognizer/BlinkID/Generic/Common/BarcodeResult.h>
#include <Recognizer/BlinkID/Generic/Common/ClassInfo.h>
#include <Recognizer/BlinkID/Generic/Common/DriverLicenseDetailedInfo.h>
#include <Recognizer/BlinkID/Generic/Common/ImageAnalysisResult.h>
#include <Recognizer/BlinkID/Generic/Common/ImageOptions.h>
#include <Recognizer/BlinkID/Generic/Common/ImageResult.h>
#include <Recognizer/BlinkID/Generic/Common/ProcessingStatus.h>
#include <Recognizer/BlinkID/Generic/Common/RecognitionMode.h>
#include <Recognizer/BlinkID/Generic/Common/RecognitionModeFilter.h>
#include <Recognizer/BlinkID/Generic/Common/VIZResult.h>
#include <Recognizer/BlinkID/MRTD/MRZResult.h>
#include <Recognizer/Export.h>
#include <Recognizer/Recognizer.h>
#include <Recognizer/RecognizerError.h>
#include <Recognizer/Types.h>
#include <Utils/Date.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct MBBlinkIdRecognizerSettings;

/**
 * @brief Typedef for the MBBlinkIdRecognizerSettings structure.
 */
MB_EXPORTED_TYPE typedef struct MBBlinkIdRecognizerSettings MBBlinkIdRecognizerSettings;

/**
 * @memberof MBBlinkIdRecognizerSettings
 * @brief Populate MBBlinkIdRecognizerSettings structure with default values.
 * @return Nothing
 */
MB_API void MB_CALL blinkIdRecognizerSettingsDefaultInit( MBBlinkIdRecognizerSettings * );

/**
 * @struct MBBlinkIdRecognizerSettings
 * @brief Settings for configuring MBBlinkIdRecognizer
 */
struct MBBlinkIdRecognizerSettings
{
    /** Whether blured frames filtering is allowed */
    MBBool allowBlurFilter;

    /** Whether returning of unparsed MRZ (Machine Readable Zone) results is allowed */
    MBBool allowUnparsedMrzResults;

    /**
     * Whether returning unverified MRZ (Machine Readable Zone) results is allowed
     * Unverified MRZ is parsed, but check digits are incorrect.
     */
    MBBool allowUnverifiedMrzResults;

    /**
     * Pading is a minimum distance from the edge of the frame and is defined
     * as a percentage of the frame width. Default value is 0.0f and in that case
     * padding edge and image edge are the same.
     */
    float paddingEdge;

    /**
     * Whether result characters validatation is performed.
     * If a result member contains invalid character, the result state cannot be valid.
     */
    MBBool validateResultCharacters;

    /**
     * Whether sensitive data should be removed from images, result fields or both.
     * The setting only applies to certain documents.
     */
    MBAnonymizationMode anonymizationMode;

    /**
     * Enable or disable recognition of specific document groups supported by the current license.
     * By default all modes are enabled.
    */
    MBRecognitionModeFilter recognitionModeFilter;

    /**
     * Image options for the fullDocumentImage.
     */
    MBFullDocumentImageOptions fullDocumentImageOptions;

    /**
     * Options for the faceImage.
     */
    MBImageOptions faceImageOptions;

    /**
     * Options for the signatureImage.
     */
    MBImageOptions signatureImageOptions;

    /**
     * Configure the recognizer to only work on already cropped and dewarped images.
     * This only works for still images - video feeds will ignore this setting.
     * Default: false.
     */
    MBBool scanCroppedDocumentImage;

    /**
     * Called when dewarped full document image is available.
     */
    void (*dewarpedImageCallback)( MBRawImage image );

    /**
     * Called when recognizer classifies document.
     * @param supported - true if supported, false otherwise
     */
    void (*classifierCallback)( MBBool supported );

    /**
     * Called when barcode scanning step starts.
     */
    void (*barcodeScanningStartedCallback)();

    /**
     * Called when recognizer classifies document as a supported class.
     * Enables filtering based on class.
     *
     * @param classInfo - classInfo of the document
     * @return should class be processed: true process, false skip
     */
    MBBool (*classFilter)( MBClassInfo classInfo );

#ifdef __cplusplus
    MBBlinkIdRecognizerSettings()
    {
        blinkIdRecognizerSettingsDefaultInit( this );
    }
#endif
};

/**
 * @struct MBBlinkIdRecognizerCommonResult
 * @brief Structure containing common fields for both result of the MBBlinkIdRecognizer and MBBlinkIdCombinedRecognizer
 */
struct MBBlinkIdRecognizerCommonResult
{
    /** Base result common to all recognizer results. */
    MBBaseRecognizerResult baseResult;

    /** The first name of the document owner. */
    char const * firstName;

    /** The last name of the document owner. */
    char const * lastName;

    /** The full name of the document owner. */
    char const * fullName;

    /** The additional name information of the document owner. */
    char const * additionalNameInformation;

    /** The localized name of the document owner. */
    char const * localizedName;

    /** The address of the document owner. */
    char const * address;

    /** The additional address information of the document owner. */
    char const * additionalAddressInformation;

    /** The place of birth of the document owner. */
    char const * placeOfBirth;

    /** The nationality of the documet owner. */
    char const * nationality;

    /** The race of the document owner. */
    char const * race;

    /** The religion of the document owner. */
    char const * religion;

    /** The profession of the document owner. */
    char const * profession;

    /** The marital status of the document owner. */
    char const * maritalStatus;

    /** The residential status of the document owner. */
    char const * residentialStatus;

    /** The employer of the document owner. */
    char const * employer;

    /** The sex of the document owner. */
    char const * sex;

    /** The date of birth of the document owner. */
    MBDate dateOfBirth;

    /** The date of issue of the document. */
    MBDate dateOfIssue;

    /** The date of expiry of the document. */
    MBDate dateOfExpiry;

    /** Determines if date of expiry is permanent. */
    MBBool dateOfExpiryPermanent;

    /** The document number. */
    char const * documentNumber;

    /** The personal identification number. */
    char const * personalIdNumber;

    /** The additional number of the document. */
    char const * documentAdditionalNumber;

    /** The one more additional number of the document. */
    char const * documentOptionalAdditionalNumber;

    /** The issuing authority of the document. */
    char const * issuingAuthority;

    /** The data extracted from the machine readable zone. */
    MBMRZResult mrz;

    /** The data extracted from the barcode. */
    MBBarcodeResult barcode;

    /** The driver license detailed info. */
    MBDriverLicenseDetailedInfo driverLicenseDetailedInfo;

    /** Contains country, region and type of scanned document. */
    MBClassInfo classInfo;

    /** Image of the person's face. */
    MBImageResult faceImage;

    /** Signature image extracted from the document. */
    MBImageResult signatureImage;

    /** Status of the last recognition process. */
    MBProcessingStatus processingStatus;

    /** Recognition mode used to scan current document. */
    MBRecognitionMode recognitionMode;
};

/**
 * @brief Typedef for the MBBlinkIdRecognizerCommonResult structure.
 */
MB_EXPORTED_TYPE typedef struct MBBlinkIdRecognizerCommonResult MBBlinkIdRecognizerCommonResult;

/**
 * @struct MBBlinkIdRecognizerResult
 * @brief Result of the MBBlinkIdRecognizer
 */
struct MBBlinkIdRecognizerResult
{
    /** Fields common to both BlinkIdRecognizer and BlinkIdCombinedRecognizer */
    MBBlinkIdRecognizerCommonResult common;

    /** Image of the scanned document. */
    MBImageResult fullDocumentImage;

    /** Various information obtained by analysing the scanned image. */
    MBImageAnalysisResult imageAnalysisResult;

    /** The data extracted from the visual inspection zone. */
    MBVIZResult viz;
};

/**
 * @brief Typedef for the GenericIDRecognizerResult structure.
 */
MB_EXPORTED_TYPE typedef struct MBBlinkIdRecognizerResult MBBlinkIdRecognizerResult;

/**
 * @struct MBBlinkIdRecognizer
 * @brief A recognizer that can scan and parse identity cards
 */
struct MBBlinkIdRecognizer;

/**
 * @brief Typedef for the MBBlinkIdRecognizer structure.
 */
typedef struct MBBlinkIdRecognizer MBBlinkIdRecognizer;

/**
 * @memberof MBBlinkIdRecognizer
 * @brief Allocates and initializes new GenericIDRecognizer object.
 * @param blinkIdRecognizer Pointer to pointer referencing the created GenericIDRecognizer object.
 * @param blinkIdRecognizerSettings Settings that will be used for creating of the GenericIDRecognizer object.
 * @return status of the operation. The operation may fail (i.e. if license key is not set or does not allow
 *         usage of the requested recognizer), so please check the returned status for possible errors.
 */
MB_API MBRecognizerErrorStatus MB_CALL blinkIdRecognizerCreate( MBBlinkIdRecognizer ** blinkIdRecognizer, MBBlinkIdRecognizerSettings const * blinkIdRecognizerSettings );

/**
 * @memberof MBBlinkIdRecognizer
 * @brief Updates the GenericIDRecognizer with the new settings.
 * Note that updating the recognizer while it is being in use by MBRecognizerRunner will fail.
 * @param blinkIdRecognizer GenericIDRecognizer that should be updated with new settings.
 * @param blinkIdRecognizerSettings Settings that will be used for updating the GenericIDRecognizer object.
 * @return status of the operation. The operation may fail (i.e. if recognizer is in use by the MBRecognizerRunner),
 *         so please check the returned status for possible errors.
 */
MB_API MBRecognizerErrorStatus MB_CALL blinkIdRecognizerUpdate( MBBlinkIdRecognizer * blinkIdRecognizer, MBBlinkIdRecognizerSettings const * blinkIdRecognizerSettings );

/**
 * @memberof MBBlinkIdRecognizer
 * @brief Obtains the result from the given GenericIDRecognizer object.
 * @param result GenericIDRecognizerResult structure that will be filled with the recognized data.
 * Note that all pointers in structure will remain valid until given recognizer is
 * destroyed with blinkIdRecognizerDelete function or is used for performing the new recognition.
 * @param blinkIdRecognizer GenericIDRecognizer from which result should be obtained.
 * @return status of the operation.
 */
MB_API MBRecognizerErrorStatus MB_CALL blinkIdRecognizerResult( MBBlinkIdRecognizerResult * result, MBBlinkIdRecognizer const * blinkIdRecognizer );

/**
 * @memberof MBBlinkIdRecognizer
 * @brief Destroys the given GenericIDRecognizer.
 * @param blinkIdRecognizer Pointer to pointer to GenericIDRecognizer structure that needs to be destroyed.
 * After destruction, the pointer to GenericIDRecognizer structure will be set to NULL.
 * @return status of the operation
 */
MB_API MBRecognizerErrorStatus MB_CALL blinkIdRecognizerDelete( MBBlinkIdRecognizer ** blinkIdRecognizer );

#ifdef __cplusplus
}
#endif

#endif
