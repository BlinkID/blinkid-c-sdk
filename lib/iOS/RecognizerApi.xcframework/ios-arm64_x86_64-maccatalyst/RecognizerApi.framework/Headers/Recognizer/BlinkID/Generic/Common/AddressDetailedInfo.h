/**
* @file AddressDetailedInfo.h
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
#ifndef ADDRESS_DETAILED_INFO_H_INCLUDED
#define ADDRESS_DETAILED_INFO_H_INCLUDED

#include <Recognizer/Export.h>

/** Detailed info about the document owner. */
struct MBAddressDetailedInfo
{
    /** The address street portion of the document owner. */
    char const * street;

    /** The address postal code portion of the document owner. */
    char const * postalCode;

    /** The address city portion of the document owner. */
    char const * city;

    /** The address jurisdiction code portion of the document owner. */
    char const * jurisdiction;
};

/**
* @brief Typedef for MBAddressDetailedInfo struct.
*/
MB_EXPORTED_TYPE typedef struct MBAddressDetailedInfo MBAddressDetailedInfo;
#endif
