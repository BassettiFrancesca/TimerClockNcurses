//
// Created by Francesca on 16/09/2017.
//

#ifndef CTD_GUICLOCK_H
#define CTD_GUICLOCK_H

#include "DatePrinter.h"
#include "TimePrinter.h"

class GUIClock {
public:
    GUIClock(DatePrinter* d,TimePrinter* t) : datePrinter(d), timePrinter(t) {}

    void printDate() {
        datePrinter->print();
    }

    void printTime() {
        timePrinter->print();
    }

private:
    DatePrinter* datePrinter;
    TimePrinter* timePrinter;
};


#endif //CTD_GUICLOCK_H
