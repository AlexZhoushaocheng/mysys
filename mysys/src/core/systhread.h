/**
 * @file systhread.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MYSYS_SRC_CORE_SYSTHREAD_H_
#define MYSYS_SRC_CORE_SYSTHREAD_H_

#include <thread>
#include <atomic>
#include <memory>

#include "object.h"
#include "eventdispatcher.h"

namespace mysys {

class Thread;


class ThreadData {
 public:
  using Ptr = std::shared_ptr<ThreadData>;
  using WeakPtr = std::weak_ptr<ThreadData>;

  ThreadData();
  ~ThreadData();

  static std::shared_ptr<ThreadData> current();

  EventDispatcher& getDispatcher();

 public:
  std::weak_ptr<Thread> thread{};

 private:
  std::thread::id thread_id_;
  EventDispatcher dispatcher_;
};


class Thread:public Object {
 public:
  Thread();

  virtual ~Thread();

  void start();

  void wait();

  bool isRunning() { return running_.load(); }

 protected:
  int exec();

  virtual void run();

 private:
  ThreadData::Ptr data;

  // hold self use count
  std::shared_ptr<Thread> self;

  std::thread th;

  std::atomic_bool running_{false};

  friend class ThreadData;
};

class AdoptedThread : public Thread {
 private:
  void run();
};

}  // namespace mysys

#endif  // MYSYS_SRC_CORE_SYSTHREAD_H_
