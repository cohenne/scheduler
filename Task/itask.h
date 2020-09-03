//
// Created by a on 9/2/20.
//

#ifndef TRY_OS_ITASK_H
#define TRY_OS_ITASK_H

#include <iostream>

struct ITask{
    virtual ~ITask(){}
    virtual void run()=0;
    virtual size_t getNextRunPeriod() const = 0;

};



#endif //TRY_OS_ITASK_H
