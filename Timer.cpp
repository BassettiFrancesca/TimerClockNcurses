//
// Created by Francesca on 17/09/2017.
//

#include "Timer.h"
#include "TimePrinter24.h"
#include <ncurses.h>
#include <ctime>

void Timer::getInput() {
    int col, row, ch1, ch2, c1, c2;
    getmaxyx(stdscr,col,row);
    init_pair(4,COLOR_WHITE,COLOR_BLUE);
    attron(COLOR_PAIR(4));
    do {
        clear();
        mvprintw(col/2,row/2,"Insert hours that should pass");
        ch1 = getch();
        ch2 = getch();
        c1 = ch1 - 48;
        c2 = ch2 - 48;
    } while ( !(ch1 >= 48 && ch1 <= 57 && ch2 >= 48 && ch2 <= 57) );
    h = c1*10 + c2;
    do {
        clear();
        mvprintw(col/2,row/2,"Insert minutes");
        refresh();
        ch1 = getch();
        ch2 = getch();
        c1 = ch1 - 48;
        c2 = ch2 - 48;
    } while ( !(ch1 >= 48 && ch1 <= 57 && ch2 >= 48 && ch2 <= 57) );
    m = c1*10 + c2;
    do {
        clear();
        mvprintw(col/2,row/2,"Insert seconds");
        refresh();
        ch1 = getch();
        ch2 = getch();
        c1 = ch1 - 48;
        c2 = ch2 - 48;
    } while ( !(ch1 >= 48 && ch1 <= 57 && ch2 >= 48 && ch2 <= 57) );
    s = c1*10 + c2;
    attroff(COLOR_PAIR(4));
    clear();
}

void Timer::stopAt() {
    int col,row,sec;
    getmaxyx(stdscr,col,row);
    time_t rawtime, rTime, cTime;
    struct tm * timeinfo;
    double diff;
    init_pair(3,COLOR_WHITE,COLOR_BLUE);
    attron(COLOR_PAIR(3));
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_hour += h;
    timeinfo->tm_min += m;
    timeinfo->tm_sec += s;
    time_t rT = mktime(timeinfo);
    curs_set(FALSE);
    do{
        time(&rTime);
        diff = difftime(rT,rTime);
        sec = (int)diff;
        clock->setSeconds((sec%3600)%60);
        clock->setMinutes(((sec - clock->getSeconds())%3600)/60);
        clock->setHour((sec-clock->getSeconds()-clock->getMinutes())/3600);
        TimePrinter24* printer = new TimePrinter24(clock);
        printer->printT();
        refresh();
        do{time(&cTime);}while(cTime==rTime);
        clear();
        delete printer;
    }while(rTime != rT);
    clear();
    mvprintw(col/2,row/2,"TIME IS UP!");
    refresh();
    attroff(COLOR_PAIR(3));
    getch();
}



