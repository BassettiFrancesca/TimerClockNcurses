//
// Created by Francesca on 15/09/2017.
//

#ifndef CTD_CLOCK_H
#define CTD_CLOCK_H

#include <ctime>

class Clock {
public:
    Clock(){
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        setTime();
        setDate();
    }

    void setTime();
    void setDate();

    bool operator==(const Clock& right) const;

    time_t getRawtime() const {
        return rawtime;
    }

    void setRawtime(time_t rawtime) {
        Clock::rawtime = rawtime;
    }

    tm *getTimeinfo() const {
        return timeinfo;
    }

    void setTimeinfo(tm *timeinfo) {
        Clock::timeinfo = timeinfo;
    }

    int getDayW() const;

    void setDayW(int dayW);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);

    int getDayM() const;

    void setDayM(int dayM);

    int getHour() const;

    void setHour(int hour);

    int getMinutes() const;

    void setMinutes(int minutes);

    int getSeconds() const;

    void setSeconds(int seconds);

private:
    time_t rawtime;
    struct tm * timeinfo;
    int dayW;
    int month;
    int year;
    int dayM;
    int hour;
    int minutes;
    int seconds;
};


#endif //CTD_CLOCK_H
