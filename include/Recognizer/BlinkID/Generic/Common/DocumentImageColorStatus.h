/**
 *  @file DocumentImageColorStatus.h
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

#ifndef DOCUMENTIMAGECOLORSTATUS_H_INCLUDED
#define DOCUMENTIMAGECOLORSTATUS_H_INCLUDED

/**
 * MBDocumentImageColorStatus enum defines possible color statuses determined from scanned image.
 */
enum MBDocumentImageColorStatus
{
    /** Determining image color status was not performed */
    MB_DOCUMENT_IMAGE_COLOR_STATUS_NOT_AVAILABLE = 0,

    /** Black-and-white image scanned */
    MB_DOCUMENT_IMAGE_COLOR_STATUS_BLACK_AND_WHITE,

    /** Color image scanned */
    MB_DOCUMENT_IMAGE_COLOR_STATUS_COLOR
};

/**
 * @brief Typedef for MBDocumentImageColorStatus enum.
 */
MB_EXPORTED_TYPE typedef enum MBDocumentImageColorStatus MBDocumentImageColorStatus;

#endif
