#include "include/Scheduler.h"

int main()
{

    Server serv(true, true);
    Scheduler sched(serv);
    LightSensor ls;
    SoundSensor ss;
    TemperatureSensor ts;
    HumiditySensor hs;
    HumiditySensor hs2;
    sched.add_sensor(ls);
    sched.add_sensor(ss);
    sched.add_sensor(ts);
    sched.add_sensor(hs);
    sched.add_sensor(hs2);
    for(std::size_t i = 0; i < 10; i++){
        sched.update();
    }
    return 0;
}
