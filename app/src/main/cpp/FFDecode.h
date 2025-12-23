//
// Created by A on 2025/12/22.
//

#ifndef XPLAY_FFDECODE_H
#define XPLAY_FFDECODE_H


#include "XParameter.h"
#include "IDecode.h"
extern "C"{
#include <libavutil/frame.h>
#include <libavcodec/avcodec.h>
};
struct AVCodecContext;

class FFDecode:public IDecode {
public:
    virtual bool Open(XParameter para);
    //future模型，发送数据到线程解码
    virtual bool SendPacket(XData pkt);

    //从线程中获取解码结果,再次调用会服用上次空间（线程不安全）
    virtual XData RecvFrame();

protected:
    AVCodecContext *codec = 0;
    AVFrame *frame = 0;
};


#endif //XPLAY_FFDECODE_H
