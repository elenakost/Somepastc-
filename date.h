#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>

class DateClass{
public:
    DateClass();
    DateClass(int MonthArg, int DayArg, int YearArg);
    
    bool Read(istream & InFile);
    void SetDate(int MonthArg,int DayArg,int YearArg);
    void Write(ostream & OutFile) const;
    
    bool operator == (const DateClass Date2) const;
    bool operator != (const DateClass Date2) const;
    bool operator < (const DateClass Date2) const;
    bool operator <= (const DateClass Date2) const;
    bool operator > (const DateClass Date2) const;
    bool operator >= (const DateClass Date2) const;
    
private:
    int Month;
    int Day;
    int Year;
};

#endif // DATE_H_INCLUDED
#include "date.cpp"