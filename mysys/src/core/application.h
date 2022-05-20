/**
 * @file mysys.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MYSYS_SRC_CORE_APPLICATION_H_
#define MYSYS_SRC_CORE_APPLICATION_H_

#include <memory>
#include "object.h"

namespace mysys {
class Thread;

#define mySys MySys::instance()

class Application : public Object{
 public:
  Application();
  ~Application();

  static Application* instance() { return self; }

  int exec();

  static std::shared_ptr<Thread> mainThread;
 private:
  static Application* self;
};

}  // namespace mysys

#endif  // MYSYS_SRC_CORE_APPLICATION_H_
