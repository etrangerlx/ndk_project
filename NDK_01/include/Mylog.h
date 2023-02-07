//
// Created by rainbow on 2022/9/17.
//

#ifndef NDK_PROJECT_MYLOG_H
#define NDK_PROJECT_MYLOG_H
#define TMP_BUFFER_LENGTH 256

#define LOG_LEVELE 0x0
#define LOG_LEVELW 0x1
#define LOG_LEVELI 0x2
#define LOG_LEVELD 0x4
#define LOG_LEVELV 0x8

#define TAG "HELLO_ALGO"

#include <string.h>


class LOG{
private:
    int loglevel = 0x0;
public:
    LOG();
    void setLoglevel(int level);
    int getLoglevel();
};

static LOG MYLOG;
#ifdef ANDROID
#include <android/log.h>
#define __FILENAME__ (strrchr(__FILE__, '/') + 1)
#define ALGO_VERBOSE(format, ...) {\
    if (MYLOG.getLoglevel() >= LOG_LEVELV){\
        __android_log_print(ANDROID_LOG_VERBOSE, TAG,\
        "[%s][%s][%d]: " format, __FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);\
    }\
    }

#define ALGO_DEBUG(format, ...) {\
    if(MYLOG.getLoglevel() >= LOG_LEVELD){\
        __android_log_print(ANDROID_LOG_DEBUG, TAG,\
        "[%s][%s][%d]: " format, __FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);\
    }\
    }

#define ALGO_INFO(format, ...) {\
    if(MYLOG.getLoglevel() >= LOG_LEVELI){\
        __android_log_print(ANDROID_LOG_INFO, TAG,\
        "[%s][%s][%d]: " format, __FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);\
    }\
    }

#define ALGO_WARN(format, ...) {\
    if(MYLOG.getLoglevel()  >= LOG_LEVELW){\
        __android_log_print(ANDROID_LOG_WARN, TAG,\
        "[%s][%s][%d]: " format, __FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);\
    }\
    }

#define ALGO_ERROR(format, ...) {\
    if(MYLOG.getLoglevel()  >= LOG_LEVELW){\
        __android_log_print(ANDROID_LOG_ERROR, TAG,\
        "[%s][%s][%d]: " format, __FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__);\
    }\
    }

#elif defined(_WIN32)
    #define __FILENAME__ (strrchr(__FILE__, '\\') + 1)
    #define ALGO_VERBOSE(format, ...) printf("[%s][VERBOSE][%s][%s][%d]"format,TAG,\
                    __FILENAME__,__FUNCTION__,__LINE__, ##__VA_ARGS__);
    #define ALGO_DEBUG(format, ...) printf("[%s][DEBUG][%s][%s][%d]"format,TAG,\
                    __FILENAME__,__FUNCTION__,__LINE__, ##__VA_ARGS__);
    #define ALGO_INFO(format, ...) printf("[%s][INFO][%s][%s][%d]"format,TAG,\
                    __FILENAME__,__FUNCTION__,__LINE__, ##__VA_ARGS__);
    #define ALGO_WARN(format, ...) printf("[%s][WARN][%s][%s][%d]"format,TAG,\
                    __FILENAME__,__FUNCTION__,__LINE__, ##__VA_ARGS__);
    #define ALGO_ERROR(format, ...) printf("[%s][ERROR][%s][%s][%d]"format,TAG,\
                        __FILENAME__,__FUNCTION__,__LINE__, ##__VA_ARGS__)
#endif
#endif //NDK_PROJECT_MYLOG_H
