/**
 * Copyright (c)2020 Microblink Ltd. All rights reserved.
 *
 * ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
 * OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
 * WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
 * UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
 * THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
 * REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.
 */

#ifndef UTILS_DATE_H_INCLUDED
#define UTILS_DATE_H_INCLUDED

#include <Recognizer/Export.h>

#ifdef _cplusplus
extern "C" {
#endif

/**
 * @struct MBDate
 * @brief Date structure which can hold date information returned by recognizers.
 */
struct MBDate
{
    /**
     * Day in month.
     */
    int day;
    /**
     * Month in year from 1 to 12.
     */
    int month;
    /**
     * Year of the date
     */
    int year;
    /**
     * Whether the date was successfully parsed from original string.
     */
    int successfullyParsed;
    /**
     * Original string from which MBDate structure was parsed. Pointer is valid only
     * while owning RecognizerResult object is alive.
     */
    char const * originalString;
};

/**
 * @brief Typedef for MBDate structure
 */
typedef MB_EXPORTED_TYPE struct MBDate MBDate;

#ifdef _cplusplus
}
#endif

#endif
