//
// Created by Francesca on 05/10/2017.
//

#ifndef CTD_DATEPRINTERN_H
#define CTD_DATEPRINTERN_H

#include "DatePrinter.h"

class DatePrinterN : public DatePrinter {
public:
    explicit DatePrinterN(Clock* c) : DatePrinter(c) {}
    virtual void print() override;
};


#endif //CTD_DATEPRINTERN_H
