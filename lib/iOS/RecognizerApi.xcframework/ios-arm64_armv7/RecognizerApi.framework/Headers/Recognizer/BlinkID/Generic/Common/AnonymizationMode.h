/**
 *  @file AnonymizationMode.h
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

#ifndef ANONYMIZATION_MODE_INCLUDED
#define ANONYMIZATION_MODE_INCLUDED

#include <Recognizer/Export.h>

/**
 * MBAnonymizationMode specifies level of anonymization.
 */
enum MBAnonymizationMode
{
    /* Anonymization will not be performed. */
    MB_ANONYMIZATION_MODE_NONE = 0,

    /* FullDocumentImage is anonymized with black boxes
       covering sensitive data. */
    MB_ANONYMIZATION_MODE_IMAGE_ONLY,

    /* Result fields containing sensitive data are removed from result. */
    MB_ANONYMIZATION_MODE_RESULT_FIELDS_ONLY,

    /* This mode is combination of ImageOnly and ResultFieldsOnly modes. */
    MB_ANONYMIZATION_MODE_FULL_RESULT
};

/**
* @brief Typedef for MBAnonymizationMode struct.
*/
MB_EXPORTED_TYPE typedef enum MBAnonymizationMode MBAnonymizationMode;

#endif
