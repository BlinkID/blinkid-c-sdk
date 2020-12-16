/**
 *  @file MRZResult.h
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
#ifndef MRZRESULT_H_INCLUDED
#define MRZRESULT_H_INCLUDED

#include "Utils/Date.h"
#include "Recognizer/Types.h"

/**
 * Supported MRTD document types
 */
enum MBMRTDDocumentType
{
    MRTD_TYPE_UNKNOWN = 0,

    /** Identity card */
    MRTD_TYPE_IDENTITY_CARD,

    /** Passport */
    MRTD_TYPE_PASSPORT,

    /** Visa */
    MRTD_TYPE_VISA,

    /** US Green Card */
    MRTD_TYPE_GREEN_CARD,

    /** Malaysian PASS type IMM13P */
    MRTD_TYPE_MYS_PASS_IMM13P,

    /** Driver's license */
    MRTD_TYPE_DL,

    /** Internal travel document */
    MRTD_TYPE_INTERNAL_TRAVEL_DOCUMENT,

    /** Number of elements in this enum. */
    MRTD_TYPE_COUNT
};

/**
 * @brief Typedef for MBMRTDDocumentType enum.
 */
MB_EXPORTED_TYPE typedef enum MBMRTDDocumentType MBMRTDDocumentType;

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @struct MBMRZResult
 * @brief Result from reading Machine Readable Zone text from ID
 */
struct MBMRZResult
{
    /**
     * The entire Machine Readable Zone text from ID. This text is usually used for parsing
     * other elements.
     * NOTE: This string is available only if OCR result was parsed successfully.
     */
    char const * rawMRZString;

    /**
     * The document code. Document code contains two characters. For MRTD the first character shall
     * be A, C or I. The second character shall be discretion of the issuing State or organization except
     * that V shall not be used, and `C` shall not be used after `A` except in the crew member certificate.
     * On machine-readable passports (MRP) first character shall be `P` to designate an MRP. One additional
     * letter may be used, at the discretion of the issuing State or organization, to designate a particular
     * MRP. If the second character position is not used for this purpose, it shall be filled by the filter
     * character <code>&lt;</code>.
     */
    char const * documentCode;

    /**
     * The three-letter or two-letter code which indicate the issuing State. Three-letter codes are based
     * on Aplha-3 codes for entities specified in ISO 3166-1, with extensions for certain States. Two-letter
     * codes are based on Aplha-2 codes for entities specified in ISO 3166-1, with extensions for certain States.
     */
    char const * issuer;

    /**
     * The document number. Document number contains up to 9 characters.
     * Element does not exist on US Green Card. To see which document was scanned use {@link documentType}.
     */
    char const * documentNumber;

    /**
     * The first optional data. Contains empty string if not available.
     * Element does not exist on US Green Card. To see which document was scanned use {@link #documentType}.
     */
    char const * opt1;

    /**
     * The second optional data. Contains empty string if not available.
     * Element does not exist on Passports and Visas. To see which document was scanned use {@link #documentType}.
     */
    char const * opt2;

    /**
     * The gender of the card holder. Gender is specified by use of the single initial, capital letter F for female,
     * M for male or <code>&lt;</code> for unspecified.
     */
    char const * gender;

    /**
     * Returns nationality of the holder represented by a three-letter or two-letter code. Three-letter
     * codes are based on Alpha-3 codes for entities specified in ISO 3166-1, with extensions for certain
     * States. Two-letter codes are based on Aplha-2 codes for entities specified in ISO 3166-1, with
     * extensions for certain States.
     */
    char const * nationality;

    /**
     * The primary indentifier. If there is more than one component, they are separated with space.
     */
    char const * primaryID;

    /**
     * The secondary identifier. If there is more than one component, they are separated with space.
     */
    char const * secondaryID;

    /**
     * The alien number. Contains empty string if not available.
     * Exists only on US Green Cards. To see which document was scanned use {@link documentType}.
     */
    char const * alienNumber;

    /**
     * The application receipt number. Contains empty string if not available.
     * Exists only on US Green Cards. To see which document was scanned use {@link documentType}.
     */
    char const * applicationReceiptNumber;

    /**
     * The immigrant case number. Contains empty string if not available.
     * Exists only on US Green Cards. To see which document was scanned use {@link #documentType}.
     */
    char const * immigrantCaseNumber;

    /**
     * The full issuer name that is expanded from the three-letter or two-letter code which indicate
     * the issuing State.
     */
    char const * issuerName;

    /**
     * Full nationality of the holder, which is expanded from the three-letter or two-letter
     * nationality code.
     */
    char const * nationalityName;

    /**
     * True if all check digits inside MRZ are correct, false otherwise.
     */
    MBBool verified;

    /**
     * true if Machine Readable Zone has been parsed, false otherwise.
     */
    MBBool parsed;

    /**
     * The holder's date of birth
     */
    MBDate dateOfBirth;

    /**
     * The date of expiry
     */
    MBDate dateOfExpiry;

    /**
     * The MRTD document type of recognized document.
     */
    MBMRTDDocumentType documentType;
};

/**
 * @brief Typedef for the MBMRZResult structure.
 */
MB_EXPORTED_TYPE typedef struct MBMRZResult MBMRZResult;

#ifdef __cplusplus
}
#endif

#endif
