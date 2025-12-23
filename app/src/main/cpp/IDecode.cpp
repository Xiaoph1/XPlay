//
// Created by A on 2025/12/22.
//

#include "IDecode.h"
#include "XLog.h"

void IDecode::Update(XData pkt) {
    if (pkt.isAudio != isAudio){
        return;
    }
    while(!isExit){
        packsMutex.lock();

        if(packs.size()<maxList){
            packs.push_back(pkt);
            packsMutex.unlock();
            break;
        }
        packsMutex.unlock();
        XSleep(1);
    }
}


void IDecode::Main() {
    while(!isExit){
        packsMutex.lock();
        if (packs.empty()){
            packsMutex.unlock();
            XSleep(1);
            continue;
        }
        //取出待解码帧到pack
        XData pack = packs.front();
        packs.pop_front();
        //一个数据包解码多个结果（音频）
        if (this->SendPacket(pack)){
            while(!isExit){
                XData frame = RecvFrame();
                if(!frame.data) break;
                XLOGI("RecvFrame %d",frame.size);
                this->Notify(frame);
            }

        }
        pack.Drop();
        packsMutex.unlock();
    }
}
