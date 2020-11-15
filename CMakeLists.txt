cmake_minimum_required(VERSION 3.17)
project(TimerClockNcurses)

set(CMAKE_CXX_STANDARD 11)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(TimerClockNcurses main.cpp Clock.cpp Clock.h GUIClock.h Timer.cpp Timer.h DatePrinter.h DatePrinterN.cpp DatePrinterN.h DatePrinterT.cpp DatePrinterT.h TimePrinter.h TimePrinter12.cpp TimePrinter12.h TimePrinter24.cpp TimePrinter24.h)
target_link_libraries(TimerClockNcurses ${CURSES_LIBRARIES})