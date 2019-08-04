LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

#项目名称，最终生成的动态库是libgamedemo.so
LOCAL_MODULE := gamedemo

#C语言编译选项
LOCAL_CFLAGS := -DDEBUG -DANDROID_OS

#C++编译选项
LOCAL_CPPFLAGS := -DDEBUG -DANDROID_OS

# C++源文件
LOCAL_SRC_FILES := game-jni.cpp \
                   GameObject.cpp \
                   Environment.cpp \
                   DataObject/DataObject.cpp \
                   GLObject/GLEnvironment.cpp \
                   GLObject/GLObject.cpp \
                   GLObject/Shader.cpp \
                   Util/Matrix.cpp \
                   Util/FileHandle.cpp \
                   Util/File.cpp \
                   Util/Android/AndroidFileHandle.cpp \


#头文件目录
LOCAL_C_INCLUDES := Util \
                    Util/Android \
                    DataObject \
                    GLObject \

#需要连接的动态库
LOCAL_LDLIBS := -llog \
                -landroid \
                -lGLESv3 \
                -lEGL \

include $(BUILD_SHARED_LIBRARY)

