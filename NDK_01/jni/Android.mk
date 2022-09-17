LOCAL_PATH      := $(call my-dir)
# 指定obj输出目录
# $(warning $(NDK_PROJECT_PATH))
# $(warning $(NDK_APP_OUT))
# $(warning $(LOCAL_MODULE_PATH))
# NDK_APP_OUT := $(LOCAL_PATH)/Install/obj
# 指定输出目录
# NDK_APP_DST_DIR := $(LOCAL_PATH)/Install/libs/$(TARGET_ARCH_ABI)
# include $(CLEAR_VARS)
# # LOCAL_MODULE, LOCAL_SRC_FILES, LOCAL_STATIC_LIBRARIES等等,但不清理LOCAL_PATH。
# $(warning "当前路径:$(LOCAL_PATH)")
# LOCAL_MODULE    := Mylog
# LOCAL_SRC_FILES := $(LOCAL_PATH)/../src/Mylog.cpp
# LOCAL_C_INCLUDE := $(LOCAL_PATH)/../include
# LOCAL_LDLIBS    := -llog
# include $(PREBUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := main
# LOCAL_SHARED_LIBRARIES := Mylog
LOCAL_SRC_FILES := $(LOCAL_PATH)/../main.cpp\
                   $(LOCAL_PATH)/../src/Mylog.cpp

LOCAL_C_INCLUDE := $(LOCAL_PATH)/../include
LOCAL_LDLIBS    := -llog
#  \$(LOCAL_PATH)/../libs/arm64-v8a/libMylog.so
include $(BUILD_EXECUTABLE)