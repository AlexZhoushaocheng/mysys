/**
 * @file systhread.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "systhread.h"

#include <assert.h>

#include <functional>
#include <memory>
#include <mutex>
#include <thread>

#include "application.h"

namespace mysys {

thread_local std::shared_ptr<ThreadData> current_thread_data;

static std::shared_ptr<ThreadData> get_thread_data() {
  return current_thread_data;
}

static void set_thread_data(std::shared_ptr<ThreadData> data) {
  current_thread_data = data;
}

static std::atomic_int32_t cout_{0};

ThreadData::ThreadData() {
    cout_.fetch_add(1);
  printf("thread data count: %d\n", cout_.load());
}

ThreadData::~ThreadData() {
    cout_.fetch_sub(1);
  printf("thread data count: %d\n", cout_.load());
}


std::shared_ptr<ThreadData> ThreadData::current() {
  auto data = get_thread_data();
  if (!data) {
    data = std::make_shared<ThreadData>();
    set_thread_data(data);
    auto thread = std::make_shared<AdoptedThread>();
    data->thread = thread;
    if (!Application::mainThread) {
      Application::mainThread = thread;
    }
    printf("size: %ld\n", data.use_count());
  }
  return data;
}

EventDispatcher& ThreadData::getDispatcher() { return dispatcher_; }

/**********************************************************/
Thread::Thread() {
  data = std::make_shared<ThreadData>();
  self = std::shared_ptr<Thread>(this, [](Thread*) {});
  data->thread = self;
  assert(data->thread.use_count() == 1);
}

Thread::~Thread() {}

void Thread::start() {
  th = std::thread([&]() {
      running_.store(true);

      set_thread_data(this->data);
      this->run();

      running_.store(false);
  });
}

void Thread::wait() { th.join(); }

int Thread::exec() {
  assert(data = ThreadData::current());
  return 0;
}

void Thread::run() {
    exec();
}

/*****************************************/

void AdoptedThread::run() {
    // should never be called
}
}  // namespace mysys
