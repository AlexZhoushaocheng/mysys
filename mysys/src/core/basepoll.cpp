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


namespace mysys {
BasePoll::BasePoll() {
    epollfd = epoll_create1(EPOLL_CLOEXEC);
}

int BasePoll::poll() {
    // ev.events
    // epoll_ctl()
    return 0;
}

}  // namespace mysys
