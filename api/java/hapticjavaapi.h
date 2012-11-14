/*
** =========================================================================
** Copyright (c) 2010-2011  Immersion Corporation.  All rights reserved.
**                          Immersion Corporation Confidential and Proprietary
**
** File:
**     hapticjavaapi.h
**
** Description:
**    Native functions for TS2200 haptic shim package for Android
**
** =========================================================================
*/
#include <jni.h>

#ifndef __HAPTICJAVAAPI_H__
#define __HAPTICJAVAAPI_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * Class:     com_immersion_Haptic
 * Method:    initialize
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_immersion_Haptic_initialize
  (JNIEnv *, jclass);

/*
 * Class:     com_immersion_Haptic
 * Method:    terminate
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_immersion_Haptic_terminate
  (JNIEnv *, jclass);

/*
 * Class:     com_immersion_Haptic
 * Method:    playEffect
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_immersion_Haptic_playEffect
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_immersion_Haptic
 * Method:    playTimedEffect
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_immersion_Haptic_playTimedEffect
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_immersion_Haptic
 * Method:    playEffectSequence
 * Signature: ([BII)V
 */
JNIEXPORT void JNICALL Java_com_immersion_Haptic_playEffectSequence
  (JNIEnv *, jclass, jbyteArray, jint);

/*
 * Class:     com_immersion_Haptic
 * Method:    stopPlayingEffect
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_immersion_Haptic_stopPlayingEffect
  (JNIEnv *, jclass);

/*
 * Class:     com_immersion_Haptic
 * Method:    runDiagnostic
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_immersion_Haptic_runDiagnostic
  (JNIEnv *, jclass);

/*
 * Class:     com_immersion_Haptic
 * Method:    getChipRevision
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_immersion_Haptic_getChipRevision
  (JNIEnv *, jclass);

/*
 * Class:     com_immersion_Haptic
 * Method:    getDeviceID
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_immersion_Haptic_getDeviceID
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __HAPTICJAVAAPI_H__ */

