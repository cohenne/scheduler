//
// Created by a on 9/2/20.
//
#include "go_swimming.h"

void GoSwimming::run(){
    Message();
    --_cycles;

    if (isDone()){
        _time = 0;
    }

    else{
        _time = Time::now() + _interval;
    }

}
