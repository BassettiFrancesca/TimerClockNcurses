//
// Created by Francesca on 15/09/2017.
//

#include "Clock.h"

void Clock::setDate() {
    dayM = timeinfo->tm_mday;
    dayW = timeinfo->tm_wday;
    month = timeinfo -> tm_mon + 1;
    year = timeinfo->tm_year + 1900;
}

void Clock::setTime() {
    hour = timeinfo->tm_hour;
    minutes = timeinfo->tm_min;
    seconds = timeinfo->tm_sec;
}

int Clock::getDayW() const {
    return dayW;
}

void Clock::setDayW(int dayW) {
    if ( dayW >= 1 && dayW <= 7)
        Clock::dayW = dayW;
}

int Clock::getMonth() const {
    return month;
}

void Clock::setMonth(int month) {
    if ( month >= 1 && month <= 12 )
        Clock::month = month;
}

int Clock::getYear() const {
    return year;
}

void Clock::setYear(int year) {
    Clock::year = year;
}

int Clock::getDayM() const {
    return dayM;
}

void Clock::setDayM(int dayM) {
    if ((year%400==0 || (year%4==0 && year%100!=0))  && month == 2){
        if (dayM <= 29 && dayM >= 1)
            Clock::dayM = dayM;
    }
    else if (month == 2) {
        if (dayM <= 28 && dayM >= 1)
            Clock::dayM = dayM;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (dayM <= 30 && dayM >= 1)
            Clock::dayM = dayM;
    }
    else if (dayM <= 31 && dayM >= 1)
        Clock::dayM = dayM;
}

int Clock::getHour() const {
    return hour;
}

void Clock::setHour(int hour) {
    if ( hour >= 0 && hour < 24 )
        Clock::hour = hour;
}

int Clock::getMinutes() const {
    return minutes;
}

void Clock::setMinutes(int minutes) {
    if ( minutes < 60 && minutes >= 0)
        Clock::minutes = minutes;
}

int Clock::getSeconds() const {
    return seconds;
}

void Clock::setSeconds(int seconds) {
    if ( seconds < 60 && seconds >= 0)
        Clock::seconds = seconds;
}

bool Clock::operator==(const Clock &right) const{
    if (hour == right.getHour() && minutes == right.getMinutes() && seconds == right.getSeconds())
        if (dayW == right.getDayW() && dayM == right.getDayM() && month == right.getMonth() && year == right.getYear())
            return true;
    return false;
}
