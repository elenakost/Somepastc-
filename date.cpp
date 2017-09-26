using namespace std;
#include <iostream>
#include <vector>

DateClass::DateClass()
:Month(0), Day(0), Year(0)
{
}

//---------------------------------------------------------
DateClass::DateClass(int MonthArg, int DayArg, int YearArg)
:Month(MonthArg),Day(DayArg), Year(YearArg)
{
}
//---------------------------------------------------------
bool DateClass::Read(istream & InFile)
{
    string S, MonthStr,DayStr,YearStr;
    getline(InFile,S);
    
    MonthStr=S.substr(0,S.find('/'));
    S=S.substr(S.find('/')+1,S.length()-S.find('/')-1);
    DayStr=S.substr(0,S.find('/'));
    YearStr=S.substr(S.find('/')+1,S.length()-S.find('/')-1);
    
    Month=atoi(MonthStr.c_str());
    Day=atoi(DayStr.c_str());
    Year=atoi(YearStr.c_str());
    
    return((Month!=0)&&(Day!=0)&&(Year!=0));
    
}
//---------------------------------------------------------
void DateClass::SetDate(int MonthArg,int DayArg,int YearArg)
{
    Month=MonthArg;
    Day=DayArg;
    Year=YearArg;
}
//---------------------------------------------------------
void DateClass::Write(ostream & OutFile) const
{
    OutFile.width(2);OutFile<<Month<<'/';
    OutFile.width(2);OutFile<<Day<<'/';
    OutFile.width(2);OutFile<<Year;
}
//---------------------------------------------------------
bool DateClass::operator<(const DateClass Date2)const
{
    if(Year<Date2.Year)
        return true;
    else if (Year>Date2.Year)
        return false;
    else if (Month<Date2.Month)
        return true;
    else if (Month>Date2.Month)
        return false;
    else
        return (Day<Date2.Day);
    
}
//---------------------------------------------------------
bool DateClass::operator>(const DateClass Date2) const
{
    return(!(operator==(Date2))&& !(operator<(Date2)));
}
//---------------------------------------------------------
bool DateClass::operator==(const DateClass Date2) const
{
    return ((Day==Date2.Day)&&(Month==Date2.Month)&&
            (Year==Date2.Year));
}
//---------------------------------------------------------
bool DateClass::operator !=(const DateClass Date2) const
{
    return !(operator==(Date2));
}
//---------------------------------------------------------
bool DateClass::operator>=(const DateClass Date2)const
{
    return ((operator==(Date2))||(operator>(Date2)));
}
//---------------------------------------------------------
bool DateClass::operator<=(const DateClass Date2)const
{
    return ((operator==(Date2))||(operator<(Date2)));
}
//---------------------------------------------------------
ostream& operator <<(ostream & OutFile, const DateClass &D)
{
    D.Write(OutFile);
    return (OutFile);
}
//---------------------------------------------------------
istream & operator>>(istream &InFile,DateClass &D)
{
    D.Read(InFile);
    return (InFile);
}


