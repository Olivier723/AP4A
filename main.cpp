#include <iostream>
#include <ctime>
#include "include/Scheduler.h"

int main()
{
    std::srand(std::time(nullptr));
    Scheduler sched = Scheduler();
    sched.getServer().setConsoleLog(false);
    LightSensor ls2;
    for(int i = 0; i < 10; ++i){
        sched.update();
        ls2.update();
        sched.pollSensor(ls2);
    }
    return 0;
}
