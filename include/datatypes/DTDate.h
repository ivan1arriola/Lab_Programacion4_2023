#ifndef DTDATE 
#define DTDATE

#include <string>

using namespace std;

class DTDate {
    private:
        int day;
        int month;
        int year;
    public:
        DTDate();
        DTDate(int day, int month, int year);
        int getDay();
        int getMonth();
        int getYear();
        ~DTDate();

        friend ostream& operator<<(ostream& os, const DTDate& dtDate);
};

#endif