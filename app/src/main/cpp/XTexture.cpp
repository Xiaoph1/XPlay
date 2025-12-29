//
// Created by A on 2025/12/23.
//

#include "XTexture.h"
#include "XLog.h"
#include "XEGL.h"
#include "XShader.h"

class CXTexture:public XTexture{
public:
    XShader sh;
    virtual bool Init(void *win){
        if (!win) {
            XLOGE("XTexture Init failed win is null");
            return false;
        }
        //初始化
        if (!XEGL::Get()->Init(win)) return false;
        sh.Init();



        return true;
    }
};


XTexture *XTexture::Create() {
    return new CXTexture();
}
