/**
* @file VIZResult.h
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
#ifndef VIZ_RESULT_H_INCLUDED
#define VIZ_RESULT_H_INCLUDED

#include <Recognizer/BlinkID/Generic/Common/DriverLicenseDetailedInfo.h>
#include <Recognizer/Export.h>
#include <Recognizer/Types.h>
#include <Utils/Date.h>

/**
 * VIZResult contains data extracted from the Visual Inspection Zone.
 */
struct MBVIZResult
{
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
    /** THe additional address information of the document owner. */
    char const * additionalAddressInformation;
    /** The place of birth of the document owner. */
    char const * placeOfBirth;
    /** The nationality of the document owner. */
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
    /** The additional personal identification number. */
    char const * additionalPersonalIdNumber;
    /** The issuing authority of the document. */
    char const * issuingAuthority;

    /** The driver license detailed info. */
    MBDriverLicenseDetailedInfo driverLicenseDetailedInfo;

    /** Whether the result is empty */
    int empty;
};

/**
* @brief Typedef for MBAnonymizationMode struct.
*/
MB_EXPORTED_TYPE typedef struct MBVIZResult MBVIZResult;

#endif
