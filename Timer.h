//
// Created by Francesca on 17/09/2017.
//

#ifndef CTD_TIMER_H
#define CTD_TIMER_H

#include "Clock.h"


class Timer {
public:
    explicit Timer(Clock* c) : clock(c) {}
    void getInput();
    void stopAt();

private:
    Clock* clock;
    int h, m, s;
};


#endif //CTD_TIMER_H
