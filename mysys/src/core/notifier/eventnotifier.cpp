/**
 * @file eventnotifier.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "eventnotifier.h"
#include "../systhread.h"

namespace mysys {
EventNotifier::EventNotifier(int fd):fd_(fd) {}

void EventNotifier::update() {
    // ThreadData::current()->getDispatcher();
}
}  // namespace mysys
