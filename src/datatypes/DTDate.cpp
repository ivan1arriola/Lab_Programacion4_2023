#include "../../include/datatypes/DTDate.h"

#include <string>
#include <iostream>

using namespace std;

DTDate::DTDate() {}

DTDate::DTDate( DTDate* dtDate) {
    this->day = dtDate->getDay();
    this->month = dtDate->getMonth();
    this->year = dtDate->getYear();
}

DTDate::DTDate(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

int DTDate::getDay() {
    return this->day;
}

int DTDate::getMonth() {
    return this->month;
}

int DTDate::getYear() {
    return this->year;
}

DTDate::~DTDate() {}

ostream& operator<<(ostream& os, const DTDate& dtDate) {
    os << dtDate.day << "/" << dtDate.month << "/" << dtDate.year;
    return os;
}
