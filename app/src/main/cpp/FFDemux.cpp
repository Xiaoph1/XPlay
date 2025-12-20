//
// Created by A on 2025/12/20.
//

#include "FFDemux.h"
#include "XLog.h"
extern "C"{
#include <libavformat/avformat.h>
}
//打开文件，或者流媒体 rmtp,http,rtsp
bool FFDemux::Open(const char *url){

    int re = avformat_open_input(&ic,url,0,0);
    if(re != 0){
        char buf[1024] = {0};
        av_strerror(re,buf,sizeof(buf));
        XLOGE("FFDemux open %s failed!",url);
        return false;
    }
    XLOGI("FFDemux open %s success!",url);

    return true;
}

//读取一帧数据，数据由调用者清理
XData FFDemux::Read() {
    XData d;
    return d;
}

FFDemux::FFDemux(){
    static bool isFirst = true;
    if (isFirst){
        //注册所有封装器
        av_register_all();
        //注册所有解码器
        avcodec_register_all();
        //初始化网络
        avformat_network_init();
//        XLOGI("init");

        isFirst = false;
    }

}
