#include <jni.h>
#include <string>
#include <unistd.h>
#include "FFDemux.h"
#include "XLog.h"
#include "FFDecode.h"
#include <android/native_window_jni.h>

class TestObs:public IObserver{
public:
    void Update(XData d){
//        XLOGI("TestObs Update data size is %d",d.size);
    }
};

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_xplay_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";


    //测试代码
    TestObs *tobs = new TestObs();
    IDemux *de = new FFDemux();
//    de->AddObs(tobs);
    de->Open("/sdcard/1.mp4");

    IDecode *vdecode = new FFDecode;
    vdecode->Open(de->GetVPara());

    IDecode *adecode = new FFDecode;
    adecode->Open(de->GetAPara());

    de->AddObs(vdecode);
    de->AddObs(adecode);

    de->Start();
    vdecode->Start();
    adecode->Start();
//    XSleep(3000);
//    de->Stop();

    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_xplay_MainActivity_InitView(JNIEnv *env, jobject thiz, jobject surface) {
    //显示窗口初始化
    ANativeWindow *nwin = ANativeWindow_fromSurface(env,surface);
    ANativeWindow_setBuffersGeometry(nwin,outWidth,outHeight,WINDOW_FORMAT_RGBA_8888);
    ANativeWindow_Buffer wbuf;
}