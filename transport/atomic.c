/*
** =============================================================================
** Copyright (C) 2010       Immersion Corporation. All rights reserved.
**                          Immersion Corporation confidential and proprietary.
** =============================================================================
*/
/**
 * \file
 *
 * This file defines the Android atomic count implementation.
 * Use __atomic_cmpxchg from Android Bionic. Returns 0 if test and swap
 * is successful, 1 if it fails.
 *
 * \version 1.0.10.0
 */

/* Haptic Transport includes */
#include <haptictransport.h>

/* ------------------------------------------------------------------------- */
/* AtomicTestAndSet                                                          */
/* ------------------------------------------------------------------------- */
HapticResult HAPTICTRANSPORT_CALL ImTransportTestAndSetInt(
    HapticInt*  destination,
    HapticInt   setValue,
    HapticInt   testValue)
{
    /* The API must provide a non-NULL input/output argument. */
    if (!destination)
    {
        HAPTIC_ASSERT(0);
        return HAPTIC_E_INTERNAL;
    }

    /*
    ** Perform the operation.
     */
    if (__atomic_cmpxchg(testValue, setValue, destination) == 0)
    {
        return HAPTIC_S_TRUE;
    }
    else
    {
        return HAPTIC_S_FALSE;
    }
}

/* ------------------------------------------------------------------------- */
/* AtomicTest                                                                */
/* ------------------------------------------------------------------------- */
HapticResult HAPTICTRANSPORT_CALL ImTransportTestInt(
    HapticInt*  value,
    HapticInt   testValue)
{
    /* The API must provide a non-NULL input argument. */
    if (!value)
    {
        HAPTIC_ASSERT(0);
        return HAPTIC_E_INTERNAL;
    }

    /*
    ** Perform the operation.
     */
    if (__atomic_cmpxchg(testValue, testValue, value) == 0)
    {
        return HAPTIC_S_TRUE;
    }
    else
    {
        return HAPTIC_S_FALSE;
    }
}

