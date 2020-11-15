//
// Created by Francesca on 05/10/2017.
//

#include "DatePrinterT.h"
#include <ncurses.h>

void DatePrinterT::print() {
    showDay();
    int col,row;
    getmaxyx(stdscr,col,row);
    init_pair(6,COLOR_BLUE,COLOR_CYAN);
    attron(COLOR_PAIR(6));
    mvprintw(col/2,row/2+10,"%u",clock->getDayM());
    attroff(COLOR_PAIR(1));
    endwin();
    showMonth();
    initscr();
    raw();
    noecho();
    curs_set(FALSE);
    keypad(stdscr,TRUE);
    start_color();
    init_pair(1,COLOR_BLUE,COLOR_CYAN);
    attron(COLOR_PAIR(1));
    mvprintw(col/2,row/2+23,"%u",clock->getYear());
    attroff(COLOR_PAIR(6));
    getch();
}

void DatePrinterT::showDay() {
    int col,row;
    getmaxyx(stdscr,col,row);
    init_pair(7,COLOR_BLUE,COLOR_CYAN);
    attron(COLOR_PAIR(7));
    if (clock->getDayW() == 1) {
        char dayW[] = "Monday";
        mvprintw(col/2,row/2,"%s", dayW);
    }
    if (clock->getDayW() == 2) {
        char dayW[] = "Tuesday";
        mvprintw(col/2,row/2,"%s", dayW);
    }
    if (clock->getDayW() == 3) {
        char dayW[] = "Wednesday";
        mvprintw(col/2,row/2,"%s", dayW);
    }
    if (clock->getDayW() == 4) {
        char dayW[] = "Thursday";
        mvprintw(col/2,row/2,"%s", dayW);
    }
    if (clock->getDayW() == 5) {
        char dayW[] = "Friday";
        mvprintw(col/2,row/2,"%s", dayW);
    }
    if (clock->getDayW() == 6) {
        char dayW[] = "Saturday";
        mvprintw(col/2,row/2,"%s", dayW);
    }
    if (clock->getDayW() == 7) {
        char dayW[] = "Sunday";
        mvprintw(col/2,row/2,"%s", dayW);
    }
    attroff(COLOR_PAIR(7));
}

void DatePrinterT::showMonth() {
    int col,row;
    getmaxyx(stdscr,col,row);
    init_pair(8,COLOR_BLUE,COLOR_CYAN);
    attron(COLOR_PAIR(1));
    if (clock->getMonth() == 1) {
        char month[] = "January";
        mvprintw(col/2,row/2+13,"%s", month);
    }
    if (clock->getMonth() == 2) {
        char month[] = "February";
        mvprintw(col/2,row/2+13,"%s", month);
    }
    if (clock->getMonth() == 3) {
        char month[] = "March";
        mvprintw(col/2,row/2+13,"%s", month);
    }
    if (clock->getMonth() == 4) {
        char month[] = "April";
        mvprintw(col/2,row/2+13,"%s", month);
    }
    if (clock->getMonth() == 5) {
        char month[] = "May";
        mvprintw(col/2,row/2+13,"%s", month);
    }
    if (clock->getMonth() == 6) {
        char month[] = "June";
        mvprintw(col/2,row/2+13,"%s", month);
    }
    if (clock->getMonth() == 7) {
        char month[] = "July";
        mvprintw(col/2,row/2+13,"%s", month);
    }
    if (clock->getMonth() == 8) {
        char month[] = "August";
        mvprintw(col/2,row/2+13,"%s", month);
    }
    if (clock->getMonth() == 9) {
        char month[] = "September";
        mvprintw(col/2,row/2+13,"%s", month);
    }
    if (clock->getMonth() == 10) {
        char month[] = "October";
        mvprintw(col/2,row/2+13,"%s", month);
    }
    if (clock->getMonth() == 11) {
        char month[] = "November";
        mvprintw(col/2,row/2+13,"%s", month);
    }
    if (clock->getMonth() == 12) {
        char month[] = "December";
        mvprintw(col/2,row/2+13,"%s", month);
    }
    attroff(COLOR_PAIR(8));
}
