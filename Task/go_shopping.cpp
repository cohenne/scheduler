//
// Created by a on 9/2/20.
//

#include "go_shopping.h"


void GoSopping::run(){
    Message();
    --_cycles;

    if (isDone()){
        _time = 0;
    }

    else{
        _time = Time::now() + _interval;
    }
}
