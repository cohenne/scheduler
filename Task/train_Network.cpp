//
// Created by a on 9/2/20.
//

#include "train_Network.h"

void TrainNetwork::run(){
    Message();
    --_cycles;

    if (isDone()){
        _time = 0;
    }

    else{
        _time = Time::now() + _interval;
    }
}