/**
 * @file basepoll.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "basepoll.h"
#include "eventnotifier.h"
#include "easylogging++.h"

namespace mysys {

    struct epoll_event events[10];
BasePoll::BasePoll() {
    epollfd = epoll_create1(EPOLL_CLOEXEC);
}

BasePoll::~BasePoll() {

}

int BasePoll::poll() {
    // ev.events
    // epoll_ctl()

    epoll_wait(epollfd, events, 10, -1);
    return 0;
}

void BasePoll::update(EventNotifier *notifier) {
    ev.data.fd = notifier->fd();
    ev.events = EPOLLIN;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, notifier->fd(), &ev) != 0) {
      LOG(ERROR) << "添加fd失败";
      abort();
    }
}

}  // namespace mysys
