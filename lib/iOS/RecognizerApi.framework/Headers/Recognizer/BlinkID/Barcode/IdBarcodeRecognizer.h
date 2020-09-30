/**
* @file IdBarcodeRecognizer.h
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
#ifndef ID_BARCODE_RECOGNIZER_H_INCLUDED
#define ID_BARCODE_RECOGNIZER_H_INCLUDED

#include <Recognizer/BlinkBarcode/BarcodeData.h>
#include <Recognizer/BlinkID/Barcode/BarcodeDocumentType.h>
#include <Recognizer/BlinkID/Generic/Common/DriverLicenseDetailedInfo.h>
#include <Recognizer/Export.h>
#include <Recognizer/Recognizer.h>
#include <Utils/Date.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** The IdBarcodeRecognizer scans barcodes from identity documents and returns the parsed information. */
struct MBIdBarcodeRecognizerResult
{
    /** Base result common to all recognizer results. */
    MBBaseRecognizerResult baseResult;

    /** The document type deduced from the recognized barcode */
    MBBarcodeDocumentType documentType;

    /** The raw, unparsed barcode data. */
    MBBarcodeData barcodeData;

    /** The first name of the document owner. */
    char const * firstName;
    /** The middle name of the document owner. */
    char const * middleName;
    /** The last name of the document owner. */
    char const * lastName;
    /** The full name of the document owner. */
    char const * fullName;
    /** The additional name information of the document owner. */
    char const * additionalNameInformation;
    /** The address of the document owner. */
    char const * address;
    /** The street address portion of the document owner. */
    char const * street;
    /** The postal code address portion of the document owner. */
    char const * postalCode;
    /** The city address portion of the document owner. */
    char const * city;
    /** The jurisdiction code address portion of the document owner. */
    char const * jurisdiction;
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
    /** The residential stauts of the document owner. */
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

    /** The document number. */
    char const * documentNumber;
    /** The personal identification number. */
    char const * personalIdNumber;
    /** The additional number of the document. */
    char const * documentAdditionalNumber;
    /** The issuing authority of the document. */
    char const * issuingAuthority;

    /** Detailed info from DL. */
    MBDriverLicenseDetailedInfo driverLicenseDetailedInfo;
}; /* struct MBIdBarcodeRecognizer */

/**
 * @brief Typedef for the IDBarcodeRecognizerResult structure.
 */
MB_EXPORTED_TYPE typedef struct MBIdBarcodeRecognizerResult MBIdBarcodeRecognizerResult;

/**
 * @struct MBIdBarcodeRecognizer
 * @brief A recognizer that can scan and parse identity cards
 */
struct MBIdBarcodeRecognizer;

/**
 * @brief Typedef for the MBIdBarcodeRecognizer structure.
 */
typedef struct MBIdBarcodeRecognizer MBIdBarcodeRecognizer;

/**
 * @memberof MBIdBarcodeRecognizer
 * @brief Allocates and initializes new IDBarcodeRecognizer object.
 * @param barcodeIdRecognizer Pointer to pointer referencing the created IDBarcodeRecognizer object.
 * @return status of the operation. The operation may fail (i.e. if license key is not set or does not allow
 *         usage of the requested recognizer), so please check the returned status for possible errors.
 */
MB_API MBRecognizerErrorStatus MB_CALL barcodeIdRecognizerCreate( MBIdBarcodeRecognizer ** barcodeIdRecognizer );

/**
 * @memberof MBIdBarcodeRecognizer
 * @brief Obtains the result from the given IDBarcodeRecognizer object.
 * @param result IDBarcodeRecognizerResult structure that will be filled with the recognized data.
 * Note that all pointers in structure will remain valid until given recognizer is
 * destroyed with barcodeIdRecognizerDelete function or is used for performing the new recognition.
 * @param barcodeIdRecognizer IDBarcodeRecognizer from which result should be obtained.
 * @return status of the operation.
 */
MB_API MBRecognizerErrorStatus MB_CALL barcodeIdRecognizerResult( MBIdBarcodeRecognizerResult * result, MBIdBarcodeRecognizer const * barcodeIdRecognizer );

/**
 * @memberof MBIdBarcodeRecognizer
 * @brief Destroys the given IDBarcodeRecognizer.
 * @param barcodeIdRecognizer Pointer to pointer to IDBarcodeRecognizer structure that needs to be destroyed.
 * After destruction, the pointer to IDBarcodeRecognizer structure will be set to NULL.
 * @return status of the operation
 */
MB_API MBRecognizerErrorStatus MB_CALL barcodeIdRecognizerDelete( MBIdBarcodeRecognizer ** barcodeIdRecognizer );

#endif

#ifdef __cplusplus
}
#endif
