//
// Created by a on 9/2/20.
//

#ifndef TRY_OS_SCHEDULER_H
#define TRY_OS_SCHEDULER_H


#include <queue>
#include "../Task/itask.h"
#include "Time.h"
#include "../SharedPtr/SharedPtr.h"


class Scheduler{
public:
    void run();
    void append (SharedPtr<ITask>& newTask){ _queueTask.push(newTask);}

private:
    class Compare{
    public:
        bool operator()(SharedPtr<ITask>& task1, SharedPtr<ITask>& task2){
            return task1->getNextRunPeriod() > task2->getNextRunPeriod();
        }
    };

    bool shouldRun      () const{ return !_queueTask.empty();}
    void handleNextTask (SharedPtr<ITask>&);

    std::priority_queue <SharedPtr<ITask>, std::vector<SharedPtr<ITask> >, Compare> _queueTask;
};




#endif //TRY_OS_SCHEDULER_H
