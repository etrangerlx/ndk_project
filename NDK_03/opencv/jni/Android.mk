LOCAL_PATH      := $(call my-dir)


include $(CLEAR_VARS)
LOCAL_MODULE    := main
LOCAL_SRC_FILES := $(LOCAL_PATH)/../test.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include/
# LOCAL_C_INCLUDES := /rainbow/CLionProjects/NDK_Project/NDK_03/opencv/include/

$(warning $(LOCAL_C_INCLUDES))
LOCAL_LDFLAGS   :=$(LOCAL_PATH)/../arm64-v8a/libopencv_core.a
LOCAL_LDFLAGS   +=$(LOCAL_PATH)/../arm64-v8a/libopencv_imgproc.a
# LOCAL_LDLIBS    := $(LOCAL_PATH)/../arm64-v8a/
#  \$(LOCAL_PATH)/../libs/arm64-v8a/libMylog.so
include $(BUILD_EXECUTABLE)