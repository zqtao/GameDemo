#ifndef GAMEDEMO_LOGGER_H
#define GAMEDEMO_LOGGER_H

#include <android/log.h>

#ifndef LOG_TAG
#define LOG_TAG "GameDemo"
#endif

#ifdef DEBUG
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#else
#define LOGV(...)
#define LOGE(...)
#define LOGW(...)
#define LOGI(...)
#define LOGD(...)
#endif

#endif //GAMEDEMO_LOGGER_H