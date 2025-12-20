//
// Created by A on 2025/12/20.
//

#ifndef XPLAY_FFDEMUX_H
#define XPLAY_FFDEMUX_H

#include "IDemux.h"
struct AVFormatContext;

class FFDemux: public IDemux{
public:
    //打开文件，或者流媒体 rmtp,http,rtsp
    virtual bool Open(const char *url);

    //读取一帧数据，数据由调用者清理
    virtual XData Read();

    FFDemux();

private:
    AVFormatContext *ic = 0;
};


#endif //XPLAY_FFDEMUX_H
