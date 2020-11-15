#include "Clock.h"
#include "TimePrinter.h"
#include "TimePrinter12.h"
#include "TimePrinter24.h"
#include "DatePrinter.h"
#include "DatePrinterN.h"
#include "DatePrinterT.h"
#include "GUIClock.h"
#include "Timer.h"
#include <ncurses.h>

int main(){
    int col,row, ch;
    initscr();
    curs_set(FALSE);
    keypad(stdscr,TRUE);
    getmaxyx(stdscr,col,row);
    raw();
    noecho();
    start_color();
    init_pair(1,COLOR_MAGENTA,COLOR_WHITE);
    attron(COLOR_PAIR(1));
    mvprintw(col/2-1,row/2,"Choose between: ");
    mvprintw(col/2+1,row/2,"clock 24h and date with numbers (1)");
    mvprintw(col/2+2,row/2,"clock 12h and date with numbers (2)");
    mvprintw(col/2+3,row/2,"clock 24h and date with letters (3)");
    mvprintw(col/2+4,row/2,"clock 12h and date with letters (4)");
    mvprintw(col/2+5,row/2,"timer that stops at a time (5)");
    mvprintw(col/2+7,row/2,"Insert number");
    refresh();
    attroff(COLOR_PAIR(1));
    ch = getch()-48;
    clear();
    if ( ch == 5 ) {
        Clock clock;
        Timer timer(&clock);
        timer.getInput();
        timer.stopAt();
    }
    else if ( ch<5 && ch>=1 ) {
        int count = 0;
        init_pair(2, COLOR_WHITE, COLOR_BLUE);
        attron(COLOR_PAIR(2));
        mvprintw(col / 2, row / 2, "Press any key to change between date and time");
        refresh();
        attroff(COLOR_PAIR(2));
        getch();
        while (1) {
            clear();
            Clock* clock = new Clock;
            DatePrinter* date;
            TimePrinter* time;
            if ( ch == 1 ){
                time = new TimePrinter24(clock);
                date = new DatePrinterN(clock);
            }
            if ( ch == 2 ){
                time = new TimePrinter12(clock);
                date = new DatePrinterN(clock);
            }
            if ( ch == 3 ){
                time = new TimePrinter24(clock);
                date = new DatePrinterT(clock);
            }
            if ( ch == 4 ){
                time = new TimePrinter12(clock);
                date = new DatePrinterT(clock);
            }
            if (count % 2){
                date->print();
            }
            else
                time->print();
            count++;
            delete clock, date, time;
        }
    }
    else
        mvprintw(col/2,row/2,"Wrong number");
    refresh();
    attroff(COLOR_PAIR(1));
    getch();
    endwin();
    return 0;
}

// provare a stampare quello che uno scrive e se inserisce <10 solo una cifra nel timer
// far chiudere l'applicazione nel timer e far riprovare se uno non pigia da 1-5 nel menu
// spostare tutto dal main