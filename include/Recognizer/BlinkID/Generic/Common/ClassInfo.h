/**
 *  @file ClassInfo.h
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

#ifndef CLASSINFO_H_INCLUDED
#define CLASSINFO_H_INCLUDED

#include "ClassInfoTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Struct holding document's country, region and type.
 */
struct MBClassInfo
{
    /** The document country. */
    MBCountry country;

    /** The document region. */
    MBRegion region;

    /** The type of the scanned document. */
    MBDocumentType type;
};

/**
 * @brief Typedef for the MBClassInfo structure.
 */
MB_EXPORTED_TYPE typedef struct MBClassInfo MBClassInfo;

#ifdef __cplusplus
}
#endif

#endif
