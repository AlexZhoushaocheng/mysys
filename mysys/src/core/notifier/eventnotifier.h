/**
 * @file eventnotifier.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MYSYS_SRC_CORE_NOTIFIER_EVENTNOTIFIER_H_
#define MYSYS_SRC_CORE_NOTIFIER_EVENTNOTIFIER_H_

namespace mysys {

class EventNotifier {
 public:
  explicit EventNotifier(int fd);
  
  void update();

  int fd() { return fd_; }

 private:
  int fd_{0};
};

}  // namespace mysys

#endif  // MYSYS_SRC_CORE_NOTIFIER_EVENTNOTIFIER_H_
