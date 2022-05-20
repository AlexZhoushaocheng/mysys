/**
 * @file object.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "object.h"

#include "systhread.h"

namespace mysys {

Object::Object() {
    thread_data = ThreadData::current();
}

Object::~Object() {}
}

