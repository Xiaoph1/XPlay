//
// Created by A on 2025/12/20.
//

#include "XThread.h"
#include <thread>
#include "XLog.h"
using namespace std;

void XThread::Start() {
    thread th(&XThread::ThreadMain,this);
    th.detach();
}

void XThread::Stop() {

}

void XThread::ThreadMain() {
    XLOGI("线程函数进入");
    Main();
    XLOGI("线程函数退出");
}
