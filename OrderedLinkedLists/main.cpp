//
//  main.cpp
//  Ordered Linked Lists
//
//  Created by Elena Kostandin on 2016-02-25.
//  Copyright © 2016 Elena Kostandin. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{//declare node structure
    string word;//word is the string in the node
    Node*next;//next is the pointer from the node
};



void Displaylist(Node*start){
/*this function displays the current list starting at the start*/
    
    Node*current=start;//initalize moving pointer called current
    
    
    while (current!=NULL){//going through the list until it reaches the end
        cout<<current->word<<endl;//print every word
        current=current->next;//pointer moves through the list
        
    }
    
    
}


string UpperCase(string S){
    /* Returns a copy of S with all lowercase characters converted to uppercase characters.*/
    for (int Letter = 0;Letter< S.length(); Letter++)//goes through all the letters in user input
        if ((S[Letter]>='a') && (S[Letter]<='z'))//finds lower case letters
            S[Letter]=S[Letter]-'a'+'A';//changes them to upper case
    return(S);
}

void AddAtStart (Node*&start, Node*&newentry){
/*this function adds a word at the beginnning of the list*/
    newentry->next=start;
    start=newentry;
    return;
}

Node *GetWord(){
    
    Node* newentry=new Node;
    cout<<"Please enter a word\n";
    cin>> newentry->word;
    
    return newentry;
    
}


Node*StartList(Node*newentry){
    
    Node*start=newentry;
    start->next=NULL;
    return start;
}

void AddItem(Node*start, Node*newentry){
    
    Node*previous=start;
    Node*current=start->next;
    
    while (current!=NULL){
        
        if (UpperCase(current->word)>UpperCase(newentry->word)){
            newentry->next=current;
            previous->next=newentry;
            return;}
        
        else{
            current=current->next;
            previous=previous->next;}
        
        
    }
    if (current==NULL){
        previous->next=newentry;
        newentry->next=NULL;}
    
}

int main()
{
    
    Node *start;
    
    
    Node*newentry= GetWord();
    if (UpperCase(newentry->word) != "DONE"){
        start=StartList(newentry);
        newentry= GetWord();
        
        
        
        while (UpperCase(newentry->word) != "DONE"){
            
            
            
            if (UpperCase(newentry->word)<UpperCase(start->word))
                AddAtStart(start,newentry);
            else
                AddItem(start,newentry);
            
            newentry=GetWord();
            
            
            
        }
        
        Displaylist(start);
    }
    return(0);
    
}


