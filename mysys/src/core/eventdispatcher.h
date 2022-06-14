/**
 * @file eventdispatcher.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MYSYS_SRC_CORE_EVENTDISPATCHER_H_
#define MYSYS_SRC_CORE_EVENTDISPATCHER_H_

#include "notifier/basepoll.h"
#include "notifier/eventnotifier.h"

namespace mysys {

class EventDispatcher {
 public:
  EventDispatcher();
  ~EventDispatcher() {}
  void processEvent(int* count);

 private:
  BasePoll base_poll_;
  // EventNotifier notifier_;
};

}  // namespace mysys

#endif  // MYSYS_SRC_CORE_EVENTDISPATCHER_H_
