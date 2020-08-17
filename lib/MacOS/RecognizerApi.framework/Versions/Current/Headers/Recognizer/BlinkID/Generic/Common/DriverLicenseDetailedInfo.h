/**
 *  @file DriverLicenseDetailedInfo.h
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
#ifndef DRIVERLICENSEDETAILEDINFO_H_INCLUDED
#define DRIVERLICENSEDETAILEDINFO_H_INCLUDED

/**
 * Struct containing driver license info.
 */
struct MBDriverLicenseDetailedInfo
{
    /** The restrictions to driving privileges for the United States driver license owner. */
    char const * restrictions;

    /** The additional privileges granted to the United States driver license owner. */
    char const * endorsements;

    /** The type of vehicle the driver license owner has privilege to drive. */
    char const * vehicleClass;

    /** The driver license conditions. */
    char const * conditions;
};

/**
 * @brief Typedef for the MBDriverLicenseDetailedInfo structure.
 */
MB_EXPORTED_TYPE typedef struct MBDriverLicenseDetailedInfo MBDriverLicenseDetailedInfo;

#endif
