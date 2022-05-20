/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-05-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <mutex>

#include "src/core/application.h"
#include "src/core/systhread.h"

class TestThread:public mysys::Thread{

protected:
  void run()override{
    printf("this is a new thread\n");
    exec();
  }

};
int main(int argc, char* argv[]) {
  mysys::Application app;

  TestThread th;
  TestThread th2;
  th.start();
  th2.start();
  th.wait();
  th2.wait();
  return app.exec();
}
