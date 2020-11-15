//
// Created by Francesca on 05/10/2017.
//

#ifndef CTD_TIMEPRINTER24_H
#define CTD_TIMEPRINTER24_H

#include "TimePrinter.h"

class TimePrinter24 : public TimePrinter {
public:
    explicit TimePrinter24(Clock* c) : TimePrinter(c) {}
    virtual void print() override;
    void printT();
};


#endif //CTD_TIMEPRINTER24_H
