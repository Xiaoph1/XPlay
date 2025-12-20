//
// Created by A on 2025/12/20.
//

#include "IDemux.h"
#include "XLog.h"

void IDemux::Main() {
    for (;;) {
        XData d = Read();
        XLOGI("IDemux Read %d",d.size);
        if (d.size<=0) break;
    }
}