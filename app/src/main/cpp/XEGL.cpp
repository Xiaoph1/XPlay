//
// Created by A on 2025/12/23.
//

#include "XEGL.h"
class CXEGL:public XEGL{
public:
    virtual bool Init(void *win){
        return true;
    }
};

XEGL *XEGL::Get() {
    static CXEGL egl;
    return &egl;
}