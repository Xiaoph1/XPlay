//
// Created by A on 2025/12/22.
//

#ifndef XPLAY_IDECODE_H
#define XPLAY_IDECODE_H

#include "XParameter.h"
#include "IObserver.h"

//解码，支持硬解码.
class IDecode: public IObserver {
public:
    //打开解码器
     virtual bool Open(XParameter para) = 0;
};


#endif //XPLAY_IDECODE_H
