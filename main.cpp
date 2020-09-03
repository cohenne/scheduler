#include <iostream>
#include "scheduler/scheduler.h"
#include "Task/go_swimming.h"
#include "Task/go_shopping.h"
#include "Task/home_work.h"
#include "Task/train_Network.h"


int main() {
    Scheduler scheduler;

    SharedPtr<ITask> task1(new GoSwimming(0, 13, 5000));
    SharedPtr<ITask> task2(new GoSopping(200, 10, 6000));
//    SharedPtr<ITask> task3(new HW(400, 12, 500002));
//    SharedPtr<ITask> task4(new TrainNetwork(500, 20, 500003));
//    SharedPtr<ITask> task5(new GoSwimming(800, 8, 500007));

    scheduler.append(task1);
    scheduler.append(task2);
//    scheduler.append(task3);
//    scheduler.append(task4);
//    scheduler.append(task5);

    scheduler.run();

    return 0;
}