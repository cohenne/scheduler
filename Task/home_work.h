//
// Created by a on 9/2/20.
//

#ifndef TRY_OS_HOME_WORK_H
#define TRY_OS_HOME_WORK_H


#include <unistd.h>
#include <iostream>
#include "itask.h"
#include "../scheduler/Time.h"

class HW : public ITask{

public:
    HW(size_t start, size_t cycles, size_t interval):_time(Time::now() + start), _cycles(cycles), _interval(interval){}

    void   run();
    size_t getNextRunPeriod() const { return _time.getMs();}

private:
    bool isDone()   const {return 0 == _cycles;}
    void Message()  const {std::cout << "Task: Do H.W.,  Cycle: " << _cycles << std::endl;}

    Time    _time;
    size_t  _cycles;
    size_t  _interval;
};


#endif //TRY_OS_HOME_WORK_H
