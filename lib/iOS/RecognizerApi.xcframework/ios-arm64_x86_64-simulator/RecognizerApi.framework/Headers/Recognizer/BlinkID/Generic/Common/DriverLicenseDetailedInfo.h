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

#include <Utils/Date.h>

#include <stdint.h>

/**
 * Struct containing vehicle class info.
 */
struct MBVehicleClassInfo
{
    /** The type of vehicle the driver license owner has privilege to drive. */
    char const * vehicleClass;

    /** The type of driver licence. */
    char const * licenceType;

    /** The date since licence is effective. */
    MBDate effectiveDate;

    /** The date of expiry of licence. */
    MBDate expiryDate;
};

/**
 * @brief Typedef for the MBVehicleClassInfo structure.
 */
MB_EXPORTED_TYPE typedef struct MBVehicleClassInfo MBVehicleClassInfo;

/** Maximum supported number of vehicle class info objects */
#define MAX_VEHICLE_CLASS_INFOS 5

/**
 * Struct representing multiple vehicle class infos
 */
struct MBVehicleClassInfos
{
    /** Array of MBVehicleClassInfo objects. */
    MBVehicleClassInfo infos[ MAX_VEHICLE_CLASS_INFOS ];

    /** Number of elements in the infos array, up to MAX_VEHICLE_CLASS_INFOS */
    uint8_t numberOfInfos;
};

/**
 * @brief Typedef for the MBVehicleClassInfos structure
 */
MB_EXPORTED_TYPE typedef struct MBVehicleClassInfos MBVehicleClassInfos;


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

    /** The additional information on vehicle class. */
    MBVehicleClassInfos vehicleClassesInfos;
};

/**
 * @brief Typedef for the MBDriverLicenseDetailedInfo structure.
 */
MB_EXPORTED_TYPE typedef struct MBDriverLicenseDetailedInfo MBDriverLicenseDetailedInfo;

#endif
