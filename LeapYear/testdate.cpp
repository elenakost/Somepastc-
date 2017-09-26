#include <iostream>
#include <cstdlib>
#include "date.h"
#include <vector>
using namespace std;




DateClass MaxDate(const vector<DateClass> &DateList)
//Accepts a vector of DateCLasses and returns the greatest date
{
    int biggest = 0; // A variable that contains the location of the greatest date
    
    
    //Goes through the vector and finds the greatest date
    for(int x = 0; x<2; x++)
    {
        if (DateList[biggest] < DateList[x+1] )
            biggest = (x + 1);
        
    }
    
    return(DateList[biggest]);
}


int main()
//The mainline
{
    vector <DateClass> DateList(3); //A vector of Dates
    
    //Adds the dates to the vector
    for(int x = 0; x<3; x++)
    {
        cout<< "Please enter the Date" << endl;
        cin >> DateList[x];
        cout << endl;
    }
    
    cout << "The max date is " << MaxDate(DateList);
    
}
