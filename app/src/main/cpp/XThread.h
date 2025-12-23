//
// Created by A on 2025/12/20.
//

#ifndef XPLAY_XTHREAD_H
#define XPLAY_XTHREAD_H

void XSleep(int mis);

//线程库
class XThread {
public:
    //启动线程
    virtual void Start();
    //安全停止线程(不一定成功)
    virtual void Stop();

    //入口主函数
    virtual void Main(){}

protected:
    bool isExit = false;
    bool isRuning = false;

private:
    void ThreadMain();

};


#endif //XPLAY_XTHREAD_H
