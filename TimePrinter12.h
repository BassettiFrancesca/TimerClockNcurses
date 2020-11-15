//
// Created by Francesca on 05/10/2017.
//

#ifndef CTD_TIMEPRINTER12_H
#define CTD_TIMEPRINTER12_H

#include "TimePrinter.h"

class TimePrinter12 : public TimePrinter {
public:
    explicit TimePrinter12(Clock* c);
    void turnAM();
    virtual void print() override;
private:
    bool AM;
};


#endif //CTD_TIMEPRINTER12_H
