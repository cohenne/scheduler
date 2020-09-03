//
// Created by a on 9/2/20.
//

#ifndef TRY_OS_TIME_H
#define TRY_OS_TIME_H


#include <iostream>


class Time{
public:
    Time(size_t ms):_ms(ms){}

    static Time now  ()       { return static_cast<size_t>(time(0));}
    size_t      getMs() const { return _ms;}

private:
    size_t _ms;
};


inline bool operator==(const Time& time1, const Time& time2){
    return time1.getMs() ==  time2.getMs();
}

inline Time operator+(const Time& time1, const Time& time2){
    return time1.getMs() + time2.getMs();
}


#endif //TRY_OS_TIME_H
