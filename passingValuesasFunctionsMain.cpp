//
//  main.cpp
//  Passing Values to Functions
//
//  Created by Elena Kostandin on 2016-02-17.
//  Copyright © 2016 Elena Kostandin. All rights reserved.
//

#include <iostream>
using namespace std;

void Reduce(int &numerf,int &denomf)
/*Reduces a fraction to the lowest commen number*/

{
    int count=1;//initalize count
    if (numerf>denomf && numerf<0)//checks whether the numerator or the denomonator is bigger to initalize count accordingly
        count=numerf;//initalize count to the numerator if numerator is bigger
    else
        count=denomf;//if numerator is not bigger set count to denomenator
 
    
    while (numerf%count!=0 || denomf%count!=0)//checks all numbers until it finds one that both the numerator and the denomonator divide into
    
    {
        if (denomf<0 )//if numerator is negative count goes up
            count++;
        else
            count--;//count goes through all numbers starting at the highest possible
    
    }
    
    numerf=numerf/count;//divide numerator by the available count
    denomf=denomf/count;//divide denomenator by the available count
   
    return;//return simplified numerator and denomenator
    
}

void ReadFraction (int&numer, int&denom){
    /*function that allows the user to enter a numerator and denominator and then returns the simplified value*/
    cout<<"Enter numerator";//user enters numerator
    cin>>numer;
    
    cout<<"Enter denominator";
    cin>> denom;//user enters denominator
    while (denom==0){//checks if denominator has been entered as 0
        cout<<"Not possible , try again, Enter a denominator";//if the user enters 0 they have to try again
        cin >>denom;}
    
    Reduce(numer,denom);//reduce user entered numerator and denominator
    return;
    
}

void Addfraction(int &numer,int &denom, int &numer2, int &denom2, int &numerf, int &denomf){
    /* takes in 2 numerators and denominators and adds them as fractions and then adds them in the slots of the new numerator and denominator*/
    
    numerf=(numer*denom2)+(numer2*denom);//creating new numerator when adding the fractions and places it in new slot
    denomf=denom*denom2;//creating new denominator when adding the fractions and places it in new slots
    
    
    Reduce(numerf,denomf);//reduces new numerator and denominator
    return;
    
}

void Display(int &numerf, int&denomf){
    /* Displays reduced user input and the reduced sum of the 2 fractions in fraction form*/

    
    if (numerf==0)//if numerator is 0 then the answer will always be 0
        cout<<"0";//0 is displayed
    else{
        
        if (denomf==1)//if denominator is one then numerator should just be displayed
            cout<<numerf;//display numerator
        else
            cout <<numerf<<"/"<<denomf;}// if other 2 conditions are not valid then just print the numerator and denominator in fraction form
   
    
    return;
    
}


int main()
{
    int numer;//initalize numerator of the first fraction
    int denom;//initialize denomenator of the first fraction
    int numer2;//initalize numerator of the second fraction
    int denom2;//initalize denomenator of the second fraction
    int numerf;//variable to store new numerator
    int denomf;//variable to store new denomenator
    ReadFraction(numer,denom);//user enters first fraction
    ReadFraction(numer2,denom2);//user enters second fraction
    
    Addfraction(numer,denom,numer2,denom2, numerf, denomf);//adds fractions entered by user
    
    Display(numer,denom);//display first user numerator and denominator in fraction form
    cout<< " + ";//display operation
    Display (numer2,denom2);//display second user numerator and denominator in fraction form
    cout<<" = ";//display equal sign
    Display(numerf,denomf);//displays sum of numerator and denominator in fraction form
    
    
}