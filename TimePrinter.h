//
// Created by Francesca on 05/10/2017.
//

#ifndef CTD_TIMEPRINTER_H
#define CTD_TIMEPRINTER_H

#include "Clock.h"

class TimePrinter {
public:
    explicit TimePrinter(Clock* c) : clock(c) {}
    virtual void print() = 0;
protected:
    Clock* clock;
};


#endif //CTD_TIMEPRINTER_H
