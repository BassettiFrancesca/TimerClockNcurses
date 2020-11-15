//
// Created by Francesca on 05/10/2017.
//

#ifndef CTD_DATEPRINTER_H
#define CTD_DATEPRINTER_H

#include "Clock.h"

class DatePrinter {
public:
    explicit DatePrinter(Clock* c) : clock(c) {}
    virtual void print() = 0;
protected:
    Clock* clock;
};


#endif //CTD_DATEPRINTER_H
