/**
 * @file Export.h
 *
 * Copyright (c)2015 MicroBlink Ltd. All rights reserved.
 *
 * ANY UNAUTHORIZED USE OR SALE, DUPLICATION, OR DISTRIBUTION
 * OF THIS PROGRAM OR ANY OF ITS PARTS, IN SOURCE OR BINARY FORMS,
 * WITH OR WITHOUT MODIFICATION, WITH THE PURPOSE OF ACQUIRING
 * UNLAWFUL MATERIAL OR ANY OTHER BENEFIT IS PROHIBITED!
 * THIS PROGRAM IS PROTECTED BY COPYRIGHT LAWS AND YOU MAY NOT
 * REVERSE ENGINEER, DECOMPILE, OR DISASSEMBLE IT.
 */

#ifndef EXPORT_H_INCLUDED
#define EXPORT_H_INCLUDED

#ifdef WIN32
#   ifdef BUILDING_STATIC_API
#       define MB_API
#       define MB_CALL
#   else
#       ifdef BUILDING_API
#           define MB_API __declspec( dllexport )
#       else
#           define MB_API __declspec( dllimport )
#       endif
#       define MB_CALL __stdcall
#   endif
#else
#   ifdef BUILDING_API
#       define MB_API __attribute__(( __visibility__( "default" ) ))
#   else
#       define MB_API
#   endif
#   define MB_CALL
#endif

#if defined( WIN32 ) && !defined( __clang__ )
#   define MB_EXPORTED_TYPE MB_API
#else
#   define MB_EXPORTED_TYPE
#endif

#endif
