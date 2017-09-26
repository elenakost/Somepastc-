//
//  main.cpp
//  account3
//
//  Created by Elena Kostandin on 2016-04-21.
//  Copyright © 2016 Elena Kostandin. All rights reserved.
//
#include<iostream>
#include<vector>

using namespace std;
AccountClass::AccountClass()
:Balance(0),TransDates(0),TransKinds(0),TransAmts(0),IsOpen(false)

AccountClass::AccountClass(string AcctName, string AcctOpenDate)
: Name (AcctName),OpenDate(AcctOpenDate),Balance(0),TransDates(0),TransKinds(0),TransAmts(0),IsOpen(true){
}
bool AccountClass::Deposit(double Amt,string Date)
{   if (AccountClass.IsOpen==true){
    Balance+=Amt;
    TransDates.resize(TransDates.size()+1);
    TransDates[TransDates.size()-1]=Date;
    
    TransKinds.resize(TransKinds.size()+1);
    TransKinds[TransKinds.size()-1]="Deposit";
    
    TransAmts.resize(TransAmts.size()+1);
    TransAmts[TransAmts.size()-1]=Amt;
    return(true);
}
else
    return(false);
    
    
}
void AccountClass::SpecifyAccount(string AccName, string AcctOpenDate){
    if (!IsOpen){
        Name=AcctNmae;
        OpenDate=AcctOpenDate;
        IsOpen=true;}
}

string AccountClass::GetName()const{
    return(Name);
}

bool AccountClass::Withdrawal(double Amt, string Date)
{
    TransDates.resize(TransDates.size()+1);
    TransDates[TransDates.size()-1]=Date;
    TransKinds.resize(TransKinds.size()+1);
    TransAmts.resize(TransAmts.size()+1);
    TransAmts[TransAmts.size()-1]=Amt;
    if (Amt<=Balance){
        Balance-=Amt;
        TransKinds[TransKinds.size()-1]="Withrdrawal";
        return(true);
    }
    else{
        TransKinds[TransKinds.size()-1]="Withdrawal/Failed";
        return(false);
    }
    
}

double AccountClass::GetBalance()const
{
    return(Balance);
}
void AccountClass::WriteTransactions(ostream&OutFile)const{
    OutFile.setf(ios::fixed);
    OutFile.precision(2);
    OutFile<<Name<<endl;
    OutFile<<"Acct opened on"<<OpenDate<<"Balance:"<<Balance<<endl;
    OutFile<<"Transactions"<<endl;
    for(int i=0;i<TransDates.size();i++){
        OutFile.width(12);OutFile<<TransDates[i];
        OutFile.width(22);OutFile<<TransKinds[i];
        OutFile.width(12);OutFile<<TransAmts[i]<<endl;
    }
    
}


