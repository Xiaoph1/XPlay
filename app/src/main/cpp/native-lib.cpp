#include <jni.h>
#include <string>
#include <unistd.h>
#include "FFDemux.h"
#include "XLog.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_xplay_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    IDemux *de = new FFDemux();
    de->Open("/sdcard/1.mp4");
//    for (;;) {
//        XData d = de->Read();
//        XLOGI("read data size id %d",d.size);
//    }
    de->Start();

    return env->NewStringUTF(hello.c_str());
}