//
//  main.cpp
//  assigment hailstones part 3
//
//  Created by Elena Kostandin on 2016-02-06.
//  Copyright © 2016 Elena Kostandin. All rights reserved.
//

#include <iostream>
using namespace std;
int main ()
{
    int value=1;
    int numb=1;
    int count=0;
    int largest=0;
    int topnumb=0;
    const int RANGE=200;
    
    
    while (numb>0 and numb <=RANGE){
        
        while (value!=1){
            
            if (value%2==0){
                value=value/2;
                //count++;
                
            }
            else {
                value=(value*3)+1;
                
                //count++;
            }
            count++;
        }
        if (count>largest){
            largest=count;
            topnumb=numb;
        }
        numb=numb+1;
        count=0;
        value=numb;
        
    }
    
    cout << "Number of iterations for " << topnumb << " is "<< largest <<"\n";
}


