/*
** =============================================================================
** Copyright (C) 2012       Immersion Corporation. All rights reserved.
**                          Immersion Corporation confidential and proprietary.
** ===========================================================================
*/
/**
 * \file
 *
 * Declares the platform-dependent constants, macros, types, and functions of
 * the Haptic C API and the Haptic Transport on Linux platforms.
 *
 * \version 1.0.10.0
 */

/* Prevent this file from being processed more than once. */
#ifndef _HAPTICOS_H
#define _HAPTICOS_H

/*
** Display a compile-time error if this file is used on a non-Linux platform.
*/
#ifndef __linux__
#error This file is for Linux platforms.
#endif

/* System includes. */
#include <assert.h>
#include <stddef.h>

#ifndef HAPTICAPI_EXTERN
    /**
     * Linkage specification for the Haptic C API, may be overridden by client
     * project settings.
     */
    #define HAPTICAPI_EXTERN extern
#endif

#ifndef HAPTICAPI_CALL
    /**
     * Calling convention for the Haptic C API, may be overridden by client
     * project settings.
     */
    #define HAPTICAPI_CALL
#endif

#ifndef HAPTICTRANSPORT_EXTERN
    /**
     * Linkage specification for the Immersion Haptic Transport, may be
     * overridden by client project settings.
     */
    #define HAPTICTRANSPORT_EXTERN extern
#endif

#ifndef HAPTICTRANSPORT_CALL
    /**
     * Calling convention for the Immersion Haptic Transport (used by the
     * Haptic C API), may be overridden by client project settings.
     */
    #define HAPTICTRANSPORT_CALL
#endif

/**
 * \addtogroup  DebugDefs   Debugging Constants and Macros
 */
/*@{*/

#ifndef NDEBUG
    /**
     * Used within the Haptic C API to determine whether building for debugging
     * purposes.
     */
    #define HAPTIC_DEBUG                1
#endif

/**
 * Used within the Haptic C API for assertions.
 */
#define HAPTIC_ASSERT(x)                assert(x)

/*@}*/


/**
 * \addtogroup  Types       Types
 */
/*@{*/

/**
 * 8-bit unsigned integer.
 */
typedef unsigned char                   HapticUInt8;

/**
 * Data size.
 */
typedef size_t                          HapticSize;

/*@}*/

#endif
