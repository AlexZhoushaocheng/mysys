/**
 * @file eventloop.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "eventloop.h"
#include "systhread.h"

namespace mysys {

int EventLoop::exec() {
    int count{0};
    ThreadData::current()->getDispatcher().processEvent(&count);
    return 0;
}
}  // namespace mysys
