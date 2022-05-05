/**
* @file DataMatchResult.h
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

#ifndef DATAMATCHRESULT_H_INCLUDED
#define DATAMATCHRESULT_H_INCLUDED

#include <Recognizer/Export.h>

/**
 * MBDataMatchResult enum defines data match results if any exist.
 */
enum MBDataMatchResult
{
    /* Data match not performed */
    MB_DATA_MATCH_NOT_PERFORMED = 0,

    /* Data match failed */
    MB_DATA_MATCH_FAILED,

    /* Data match succeeded */
    MB_DATA_MATCH_SUCCESS
};

/**
 * @brief Typedef for MBDataMatchResult enum.
 */
MB_EXPORTED_TYPE typedef enum MBDataMatchResult MBDataMatchResult;

#endif
