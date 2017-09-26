//
//  main.cpp
//  Recursion Assignment #6
//
//  Created by Elena Kostandin on 2016-04-11.
//  Copyright © 2016 Elena Kostandin. All rights reserved.
//

/*This program creates a grid of which is the size of the users choice filled with random '*' and counts how many'*' are around a point at which the user chooses*/
#include <iostream>
using namespace std;
#include <vector>
#include <stdlib.h>
#include <time.h>

typedef vector<char> onerow;//set up vector class
typedef vector<onerow>matrix;//set up vector class

void FillMatrix(matrix &chart){
/*This function fills the grid with '*' at random cooridinates*/
    
    for (int x=0;x<chart.size();x++){//goes through rows
        for (int i=0;i<chart[0].size();i++){//goes through colomns
            int randnum=(rand()%2);//places a random number between 1 and 0 in slots
            
            if (randnum==1)
                chart[x][i]='*';//insert '*' in 1 slots
            
            else
                chart[x][i]=' ';//insert random blanks in grid
            
            
            
            
        }
    }
    return;
    
}

void DisplayChart(const matrix &chart){
/*This function displays the list*/
    for (int x=chart.size()-1;x>=0;x--){//goes through the rows
        
        cout<<x;//prints the row number
        for (int i=0;i<chart[0].size();i++){//goes through colomns
            cout<<chart[x][i]<<" ";
        }
        cout<<endl;
    }
    for (int y=0;y<chart[0].size();y++){//used to print colomn numbers
        cout<<" "<<y;}
    return;
}

int blob_check(matrix &chart, int row, int col){
/*This function counts the number of blobs around a certain blob*/
    int count=0;//initalize counter for number of blobs
    if (row<=(chart.size()-1)&& col<=(chart[0].size()-1)&& row>=0&& col>=0){//check if blob is on the chart
        if (chart[row][col]==' ')//check if there is a blob at the point
            count=0;
        else{
            chart[row][col]=' ';//replace blob with space temporarly
            
            count=1+(blob_check(chart,row,col-1))+//counts and checks sorrounding blobs
            (blob_check(chart,row-1,col-1))+
            (blob_check(chart,row-1,col))+
            (blob_check(chart,row+1,col))+
            (blob_check(chart,row,col+1))+
            (blob_check(chart,row+1,col+1))+
            (blob_check(chart,row-1,col+1))+
            (blob_check(chart,row+1,col-1));}
        
    }
    
    
    
    else
        count=0;//if blob not on grid count is 0
    return(count);
}



int main(){
    srand(time(NULL));//timer to generate random numbers
    
    int row;//memory space for how many rows there are going to be
    cout<<"Please enter the number of rows for the grid";
    cin>>row;//user inputs number of rows
    cout<<"\nPlease enter the number of columns for the grid";
    int col;//memory space for how many colomns there are going to be
    cin>>col;//user inputs number of colomns
    
    
    matrix chart(row,onerow(col));//fill a matrix with rows and colomns
    FillMatrix(chart);
    DisplayChart(chart);
    matrix checkm=chart;//makes temprorary copy of grid
    cout<< "\nEnter a row number";
    int rowc;//memory space for the user to enter the row the blob is in to check/count blobs
    int colc;//memory space for the user to enter the column the blob is in to check/count blobs
    cin>>rowc;//user input of row blob is in
    cout<<"\nEnter a col number";
    cin>>colc;//user input of column blob is in
    cout<<"At"<<rowc<<" "<<colc<<" the blob size is "<<blob_check(checkm,rowc,colc);
    return(0);
    
    
}
