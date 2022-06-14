/**
 * @file basepoll.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-05-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef MYSYS_SRC_CORE_NOTIFIER_BASEPOLL_H_
#define MYSYS_SRC_CORE_NOTIFIER_BASEPOLL_H_

#include <sys/epoll.h>

namespace mysys {
class EventNotifier;

class BasePoll {
 public:
  BasePoll();

  ~BasePoll();

  int poll();

  void update(EventNotifier *notifier);

 private:
  int epollfd{-1};
  epoll_event ev;
};
}  // namespace mysys

#endif  // MYSYS_SRC_CORE_NOTIFIER_BASEPOLL_H_
