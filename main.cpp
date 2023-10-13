#include <iostream>
#include <ctime>
#include "include/Scheduler.h"

int main()
{
    std::srand(std::time(nullptr));
    std::cout<<"Hello, World!"<<std::endl;
    Scheduler sched = Scheduler();
    for(int i = 0; i < 10; ++i){
        sched.update();
    }
    return 0;
}
