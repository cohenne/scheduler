//
// Created by a on 9/2/20.
//
#include <unistd.h>
#include "scheduler.h"

/* ------------------- Auxiliary Functions -------------------*/


void Scheduler::handleNextTask(SharedPtr<ITask>& task){
    task->run();
    _queueTask.pop();

    if (task->getNextRunPeriod()){
        _queueTask.push(task);
    }
}

void wait(size_t timeToSleep){
    usleep(timeToSleep);
}

/* ------------------- End Auxiliary Functions ---------------*/


void Scheduler::run(){
    while (shouldRun()){
        SharedPtr<ITask> task = _queueTask.top();

        if (task->getNextRunPeriod() > Time::now().getMs()){
            wait(task->getNextRunPeriod() - Time::now().getMs());
        }

        handleNextTask(task);
    }
}




