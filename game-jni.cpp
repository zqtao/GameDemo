#include <jni.h>
#include <string>
#include "Environment.h"
#ifdef ANDROID_OS
#include "GLEnvironment.h"
#endif

using namespace std;

extern "C" JNIEXPORT jstring JNICALL
Java_com_zqtao_gamedemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

Environment* g_pEnvrionment;

static void SetEnvironment()
{
#ifdef ANDROID_OS
    g_pEnvrionment = new GLEnvironment();
#endif
}



