/*
** =============================================================================
** Copyright (C) 2010       Immersion Corporation. All rights reserved.
**                          Immersion Corporation confidential and proprietary.
** =============================================================================
*/
/**
 * \file
 *
 * Implements the device functions of the Haptic Transport on Android using i2c.
 *
 * \version 1.0.10.0
 */

/* Haptic Transport includes */
#include <haptictransport.h>

/* I2C includes */ 
#include <i2c-dev.h>   

/* OS includes */ 
#include <fcntl.h> /* O_RDWR */

#include <drv2605.h>

/*
** -----------------------------------------------------------------------------
** Private Constants
** -----------------------------------------------------------------------------
*/

/* Haptic board I2C adapter device name. OEMs/ODMs may have to change this. */
#define HAPTIC_I2CADAPTER                           "/dev/drv2605"

/*
** -----------------------------------------------------------------------------
** Private Data
** -----------------------------------------------------------------------------
*/

static int fd = -1;

/*
** -----------------------------------------------------------------------------
** Private Functions
** -----------------------------------------------------------------------------
*/

static HapticResult OpenDevice()
{
    fd = open(HAPTIC_I2CADAPTER, O_RDWR);
    if (-1 == fd)
    {
        HAPTIC_ASSERT(0);
        return HAPTIC_E_SYSTEM;
    }

    return HAPTIC_S_OK;
}

static HapticResult InitI2C()
{
    return HAPTIC_S_OK;
}

/*
** -----------------------------------------------------------------------------
** Public Functions
** -----------------------------------------------------------------------------
*/

HapticResult HAPTICTRANSPORT_CALL ImTransportOpen()
{
    HapticResult    retVal  = HAPTIC_S_OK;

    /*
    ** The API must not call this function without an intervening call to
    ** ImTransportClose().
    */
    if (-1 != fd)
    {
        HAPTIC_ASSERT(0);
        return HAPTIC_E_INTERNAL;
    }

    /* Open the device. */
    retVal = OpenDevice();
    if (HAPTIC_FAILED(retVal))
    {
        return retVal;
    }

    /* Initialize I2C communication. */
    retVal = InitI2C();
    if (HAPTIC_FAILED(retVal))
    {
        return retVal;
    }

#ifdef HAPTIC_EFFECT_BANK
    /* Initialize the effect bank. */
    retVal = InitEffectBank();
    if (HAPTIC_SUCCEEDED(retVal))
    {
        return retVal;
    }
#endif

    return HAPTIC_S_OK;
}

HapticResult HAPTICTRANSPORT_CALL ImTransportClose()
{
    HapticResult retVal = HAPTIC_S_OK;
    
    /* The API must call ImTransportOpen() before calling this function. */
    if (-1 == fd)
    {
        HAPTIC_ASSERT(0);
        return HAPTIC_E_NOT_INITIALIZED;
    }
    
    close(fd);
    fd = -1;

    return retVal;
}

HapticResult HAPTICTRANSPORT_CALL ImTransportWrite(
    const HapticUInt8*   buffer,
    HapticSize           bufferLength)
{
    HapticResult retVal = HAPTIC_S_OK;

    /*
    ** The API must provide valid arguments.
    ** The API must call ImTransportOpen() before calling this function.
    */
    if (   (0 == buffer)
        || (0 == bufferLength)
        || (-1 == fd))
    {
        HAPTIC_ASSERT(0);
        return HAPTIC_E_INTERNAL;
    }

    if (write(fd, buffer, bufferLength) <= 0)
    {
        retVal = HAPTIC_E_INTERNAL;
    }
    
    return retVal;
}

HapticResult HAPTICTRANSPORT_CALL ImTransportRead(
    HapticUInt8 *buffer, 
    HapticSize bufferLength)
{
    /*
    ** The API must provide valid arguments.
    ** The API must call ImTransportOpen() before calling this function.
    */
    if (!buffer
        || (0 >= bufferLength))
    {
        HAPTIC_ASSERT(0);
        return HAPTIC_E_INTERNAL;
    }

    if (read(fd, buffer, bufferLength) <= 0)
    {
        return HAPTIC_E_SYSTEM;
    }
    
    return HAPTIC_S_OK;
}