LOCAL_PATH := $(call my-dir)

GLOBAL_INCLUDE := $(LOCAL_PATH)/../driver \
                  $(LOCAL_PATH)/../include

include $(CLEAR_VARS)

LOCAL_MODULE            := libhaptictransport
LOCAL_C_INCLUDES        := $(GLOBAL_INCLUDE) \
                           $(LOCAL_PATH)/../transport

LOCAL_SRC_FILES         := ../transport/atomic.c \
                           ../transport/device.c \
                           ../transport/threadmutex.c \
                           ../api/c/hapticapi.c

LOCAL_CFLAGS            := -D__linux__
LOCAL_MODULE_TAGS		:= optional eng
LOCAL_PRELINK_MODULE    := false

include $(BUILD_STATIC_LIBRARY)

#---------------------------------------------------------------------------

include $(CLEAR_VARS)
LOCAL_MODULE            := libhapticapi
LOCAL_C_INCLUDES        := $(GLOBAL_INCLUDE)

LOCAL_SRC_FILES         := ../api/c/hapticapi.c

LOCAL_MODULE_TAGS		:= optional eng
LOCAL_STATIC_LIBRARIES  := libhaptictransport
LOCAL_CFLAGS            := -D__linux__

include $(BUILD_SHARED_LIBRARY)

#---------------------------------------------------------------------------

include $(CLEAR_VARS)

LOCAL_MODULE            := libhapticjavaapi
LOCAL_C_INCLUDES        := $(GLOBAL_INCLUDE)

LOCAL_SRC_FILES         := ../api/java/hapticjavaapi.c

LOCAL_LDLIBS            := -L$(LOCAL_PATH)/../libs/armeabi/
LOCAL_SHARED_LIBRARIES  := libhapticapi
LOCAL_MODULE_TAGS		:= optional eng
LOCAL_CFLAGS            := -D__linux__

include $(BUILD_SHARED_LIBRARY)
