/*
 * Copyright (C) 2010-2012 Project StarGate
 */

#ifndef TRINITY_DEFINE_H
#define TRINITY_DEFINE_H

#include <sys/types.h>

#include <ace/Basic_Types.h>
#include <ace/ACE_export.h>

#include "CompilerDefs.h"

#define TRINITY_LITTLEENDIAN 0
#define TRINITY_BIGENDIAN    1

#if !defined(TRINITY_ENDIAN)
#  if defined (ACE_BIG_ENDIAN)
#    define TRINITY_ENDIAN TRINITY_BIGENDIAN
#  else //ACE_BYTE_ORDER != ACE_BIG_ENDIAN
#    define TRINITY_ENDIAN TRINITY_LITTLEENDIAN
#  endif //ACE_BYTE_ORDER
#endif //TRINITY_ENDIAN

#if PLATFORM == PLATFORM_WINDOWS
#  define TRINITY_PATH_MAX MAX_PATH
#  ifndef DECLSPEC_NORETURN
#    define DECLSPEC_NORETURN __declspec(noreturn)
#  endif //DECLSPEC_NORETURN
#else //PLATFORM != PLATFORM_WINDOWS
#  define TRINITY_PATH_MAX PATH_MAX
#  define DECLSPEC_NORETURN
#endif //PLATFORM

#if !defined(COREDEBUG)
#  define TRINITY_INLINE inline
#else //COREDEBUG
#  if !defined(TRINITY_DEBUG)
#    define TRINITY_DEBUG
#  endif //TRINITY_DEBUG
#  define TRINITY_INLINE
#endif //!COREDEBUG

#if COMPILER == COMPILER_GNU
#  define ATTR_NORETURN __attribute__((noreturn))
#  define ATTR_PRINTF(F, V) __attribute__ ((format (printf, F, V)))
#else //COMPILER != COMPILER_GNU
#  define ATTR_NORETURN
#  define ATTR_PRINTF(F, V)
#endif //COMPILER == COMPILER_GNU

typedef ACE_INT64 int64;
typedef ACE_INT32 int32;
typedef ACE_INT16 int16;
typedef ACE_INT8 int8;
typedef ACE_UINT64 uint64;
typedef ACE_UINT32 uint32;
typedef ACE_UINT16 uint16;
typedef ACE_UINT8 uint8;

enum
{
	FT_NA='x',                                              //not used or unknown, 4 byte size
	FT_NA_BYTE='X',                                         //not used or unknown, byte
	FT_STRING='s',                                          //char*
	FT_FLOAT='f',                                           //float
	FT_INT='i',                                             //uint32
	FT_BYTE='b',                                            //uint8
	FT_SORT='d',                                            //sorted by this field, field is not included
	FT_IND='n',                                             //the same, but parsed to data
	FT_LOGIC='l',                                            //Logical (boolean)
	FT_SQL_PRESENT='p',                                      //Used in sql format to mark column present in sql dbc
	FT_SQL_ABSENT='a'                                       //Used in sql format to mark column absent in sql dbc
};

#endif //TRINITY_DEFINE_H