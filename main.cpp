#include <iostream>
#include <ctime>
#include "include/Scheduler.h"

int main()
{
    std::srand(std::time(nullptr));
    Scheduler sched = Scheduler();
    sched.getServer().setConsoleLog(false);
    for(int i = 0; i < 10; ++i){
        sched.update();
    }
    return 0;
}
