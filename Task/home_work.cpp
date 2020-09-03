//
// Created by a on 9/2/20.
//

#include "home_work.h"

void HW::run(){
    Message();
    --_cycles;

    if (isDone()){
        _time = 0;
    }

    else{
        _time = Time::now() + _interval;
    }
}