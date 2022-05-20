/**
 * @file mysys.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "application.h"

#include <assert.h>
#include "systhread.h"

namespace mysys {


Application::Application():Object() {
    self = this;
}

Application::~Application() {
}

int Application::exec() {
  assert(mainThread == ThreadData::current()->thread.lock());
  return 0;
}

Application* Application::self = nullptr;

std::shared_ptr<Thread> Application::mainThread;
}  // namespace mysys
