/**
 * @file object.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-05-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef MYSYS_SRC_CORE_OBJECT_H_
#define MYSYS_SRC_CORE_OBJECT_H_
#include <memory>

namespace mysys {

class ThreadData;

class Object {
 public:
  Object();

  virtual ~Object();

 private:
  std::shared_ptr<ThreadData> thread_data;
};

}  // namespace mysys

#endif  // MYSYS_SRC_CORE_OBJECT_H_
