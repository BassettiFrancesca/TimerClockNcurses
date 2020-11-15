//
// Created by Francesca on 05/10/2017.
//

#ifndef CTD_DATEPRINTERT_H
#define CTD_DATEPRINTERT_H

#include "DatePrinter.h"

class DatePrinterT : public DatePrinter {
public:
    explicit DatePrinterT(Clock* c) : DatePrinter(c) {}
    virtual void print() override;
    void showDay();
    void showMonth();
};


#endif //CTD_DATEPRINTERT_H
