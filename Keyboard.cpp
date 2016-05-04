#include "Keyboard.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stdlib.h>


using namespace std;

Keyboard::Keyboard()
{
    //ctor
    for (int i =0; i<Row; i++){
        keyboard[i] = NULL;
    }
}

Keyboard::~Keyboard()
{
    //dtor
    deleteKeyboard();
}

void Keyboard::createKeyboard(int row, int column){


    char alphabet = 'A';



    for(int i=0; i<row;i++){ // loop through from 0 to the row
        Key *node = new Key; //create a new Key
        node->letter = NULL;
        node->next=NULL;
        node->previous=NULL;
        if(alphabet<'Z'){ // if alphabet or the letter is less than Z
            node->letter = alphabet; //input alphabet into the node
            keyboard[i]= node; //set the first column of each row equal to node
            alphabet++;
            Key *tmp = keyboard[i]; //create a temp struct that is eual to the node.

            for(int j=0; j<column;j++){

                Key *Next = new Key; //create a new key Next
                Next->letter = NULL;
                Next->next = NULL;
                node->next = Next; //the Next struct is the struct following node
                Next->previous = node;
                node = node->next; //allow node to traverse to the next node
                node->letter = alphabet;
                tmp->next = node; //tmp is now behind node
                node->previous = tmp;

                node->next = NULL;
                tmp = tmp->next; //traverse tmp to next tmp which is node now
                alphabet++;

            }
            alphabet--;
            cout<<endl;

        }
        else{
            //letter is greater than Z (i.e. does not exist) then we make a node there but input the letter as NULL
            node->letter =NULL;
            keyboard[i]=node;
            Key *tmp = keyboard [i];
            for(int j=0; j<column;j++){
                //same formating as before;
                Key *Next = new Key;
                Next->letter = NULL;
                Next->next = NULL;
                node->next = Next;
                Next->previous = node;
                node = node->next;
                node->letter = NULL;
                tmp->next = node;
                node->previous = tmp;

                node->next = NULL;
                tmp = tmp->next;
            }
        }

    }
}

void Keyboard::printKeyboard(){
    //print each letter in the keyboard
    if(Row!=0 || Column!=0){// if the keyboard is not empty
        for (int i =0; i<Row; i++){//for all the rows
            if(keyboard[i]!=NULL){
                Key *tmp = keyboard[i]; //set tmp equal to the first node of each row

                while(tmp->next !=NULL){ //while tmp 's next is not NUll print the letter
                    if(tmp->letter!=NULL){

                        cout<< tmp->letter<<"     ";// if tmp has a letter print the letter
                    }
                    else {
                        cout<<"NULL"<<" "; // if tmp is null print null
                    }
                    tmp =tmp ->next;



                }

                if(tmp->letter==NULL){
                    cout<<"NULL";
                }
                cout<<endl<<endl;

            }

            else{
                cout<< "empty row"<<endl;
            }
        }
    }
    else{
        cout<< "The keyboard is empty."<<endl;
    }

}

bool Keyboard::isLetterInKeyboard(string letter){
    //check if the letter the user or application inputs is in the keyboard
    bool found = false;
    for (int i =0; i<Row; i++){ //look through all rows
            if(keyboard[i]!=NULL){ //if the first letter of row is not null
                Key *tmp = keyboard[i]; //make a pointer to it
                if(tmp->letter==letter[0]){
                    found = true;
                }
                while(tmp->next !=NULL){ //go through all columns
                    tmp =tmp ->next;
                    if(tmp->letter==letter[0]){
                        found = true;
                    }
                }
                cout<<endl;
            }

            else{
                cout<< "empty row"<<endl;
            }
    }
    return found;
}

void Keyboard::wordDirections(string word){
    //this function will take a word as an input and print the moves to get to each character starting from A or (0,0).
    //The keyboard can only go up and down from the first column of the keyboard and left and right from within the same row.

    // If the movement is positive then the search goes right and down.
    // If the movement is negative then the search goes left and up.

    int leftClick = 0;
    int rightClick = 0;
    int upClick = 0;
    int downClick =0;

    int *index_current;
    int *index_previous;

    int wordLength = word.size();

    for(int i =0; i<wordLength; i++){ //loop through all of the letters of the word
            // next 10 lines are to convert the letter from a char to a string to input findKeyIndex
            stringstream ss1;
            stringstream ss2;
            string letter_current;
            char letter_current_char = word[i];
            ss1 << letter_current_char;
            ss1 >> letter_current;

            string letter_previous;
            char letter_previous_char = word[i-1];
            ss2 << letter_previous_char;
            ss2 >> letter_previous;



        if(i==0){ // if it is the first letter, the search always starts with A
            index_current = findKeyIndex(letter_current); //find the key index
            downClick = *(index_current+0); // down click is the same as the row of the index
            rightClick = *(index_current+1); // right click is the same as the column
            cout<<word[i]<<": "<<rightClick<<" right clicks";
            cout<<" and "<<downClick<<" down clicks"<<endl;
        }
        else if(i!=0){ //if it is not the first letter, the search starts with the previous letters and does comparisions to the current letter

            index_current = findKeyIndex(letter_current); // index of the current letter
            index_previous = findKeyIndex(letter_previous); // index of the previous letter

            if(*(index_current+0)-*(index_previous+0)>0 && *(index_current+1)-*(index_previous+1)>0 ){
                //if movement is right and down
                downClick = *(index_current+0)-*(index_previous+0); //down click is equal to the row of the current minus the previous row
                rightClick = *(index_current+1)-*(index_previous+1); //right clicks is equal to the current column minus the previous column
                cout<<word[i]<<": "<<rightClick<<" right clicks";
                cout<<" and "<<downClick<<" down clicks"<<endl;

            }

            else if(*(index_current+0)-*(index_previous+0)>0 && *(index_current+1)-*(index_previous+1)<0 ){
                //if movement is left and down
                downClick = *(index_current+0)-*(index_previous+0); // down click is equal to the current row minus the previous row
                leftClick = *(index_previous+1)-*(index_current+1); // left click is equal to the previous column minus the current column
                cout<<word[i]<<": "<<leftClick<<" left clicks";
                cout<<" and "<<downClick<<" down clicks"<<endl;

            }
            else if(*(index_current+0)-*(index_previous+0)<0 && *(index_current+1)-*(index_previous+1)<0){
                //if movement is left and up
                upClick = *(index_previous+0)-*(index_current+0); // up clicks is the previous row minus the current row
                leftClick = *(index_previous+1)-*(index_current+1); // left clicks is the previous column minus the current column
                cout<<word[i]<<": "<<leftClick<<" left clicks";
                cout<<" and "<<upClick<<" up clicks"<<endl;
            }

            else if(*(index_current+0)-*(index_previous+0)<0 && *(index_current+1)-*(index_previous+1)>0){
                //if movement is right and up
                upClick = *(index_previous+0)-*(index_current+0); // up clicks is the previous row minus the current row
                rightClick = *(index_current+1)-*(index_previous+1); //right clicks is the current column minus the previous column
                cout<<word[i]<<": "<<rightClick<<" right clicks";
                cout<<" and " <<upClick<<" up clicks"<<endl;
            }
            else if(*(index_current+0)-*(index_previous+0)==0 && *(index_current+1)-*(index_previous+1)>0){
                //if movement is just towards the right

                rightClick = *(index_current+1)-*(index_previous+1);
                cout<<word[i]<<": "<<rightClick<<" right clicks"<<endl;

            }
            else if(*(index_current+0)-*(index_previous+0)==0 && *(index_current+1)-*(index_previous+1)<0){
                //if movement is just towards the left

                leftClick = *(index_previous+1)-*(index_current+1);
                cout<<word[i]<<": "<<leftClick<<" left clicks"<<endl;

            }
            else if(*(index_current+0)-*(index_previous+0)<0 && *(index_current+1)-*(index_previous+1)==0){
                //if movement is just upwards

                upClick = *(index_previous+0)-*(index_current+0);
                cout<<word[i]<<": "<<upClick<<" up clicks"<<endl;

            }
            else if(*(index_current+0)-*(index_previous+0)>0 && *(index_current+1)-*(index_previous+1)==0){
                //if movement is just downwards

                downClick = *(index_current+0)-*(index_previous+0);
                cout<<word[i]<<": "<<downClick<<" down clicks"<<endl;

            }
            else if(*(index_current+0)-*(index_previous+0)==0 && *(index_current+1)-*(index_previous+1)==0){
                // No movement
                cout<< "No movement necessary" <<endl;
            }

        }


    }
}


int * Keyboard::findKeyIndex(string letter){
    bool found = isLetterInKeyboard(letter);
    if(found==false){
        cout<<"The following letter is not in the keyboard: "<<letter<<endl;

    }
    else{

        //Take a letter as an input and return the index of the letter

        int row = 0;
        int column =0;
        bool found_row = false;
        bool found_column = false;
        Key *tmp = keyboard[row];


        //first find row
        while(found_row==false){
            tmp = keyboard[row];

            if(tmp->letter== letter[0]){ //if letter is the first index of the row
                found_row = true;
            }
            else if(tmp->letter + Column-1 >=letter[0]){ //if the letter is within the row
                found_row = true;
            }
            else if(tmp->letter +Column-1 < letter[0]){ //if letter is not within the row
                found_row = false;
                row++;
            }
        }
        //now finding column
        tmp = keyboard[row]; // set tmp equal to the first letter of the row found
        //keep going left till the letter is found and save column
        while(found_column == false){
            if(tmp->letter!=letter[0]){
                tmp = tmp->next;
                column++;

                if(tmp->letter == letter[0]){
                found_column = true;
                }
            }
            if(tmp->letter == letter[0]){
                found_column = true;
            }
        }
        int *index= new int[2]; //to create memory that will not be destroyed
        // index is (row,column)
        index[0] = row;
        index[1] = column;

        return index;
    }
    return 0;

}
void Keyboard::printIndexes(){
    //Printing all indexes of letters
    if (Row!=0 || Column!=0){
        for(int i=0; i < Row; i++){
            for(int j=0; j < Column; j++){
                cout<< "("<<i<<","<<j<<")   ";
            }
            cout<<endl;
            cout<<endl;
    }
    }
    else{
        cout<< "Sorry, there are no letters in the Keyboard" <<endl;
    }

}
void Keyboard::deleteKeyboard(){
    // to delete the keyboard
    for (int i =0; i<Row; i++){ //loop through all rows
        if(keyboard[i]!=NULL){ // if the first letter of the row is not null
            if(keyboard[i]->next==NULL){
                keyboard[i] = NULL; //if there is only one letter in the first row set it to NULL
            }
            else{
                Key *tmp1 = keyboard[i]; // If there is more than one letter then make tmp1 to save the row
                while(tmp1->next!=NULL){
                    Key *tmp2 = tmp1; // make tmp2 to delete tmp2 later
                    if(tmp1->next!=NULL&& tmp1->previous!=NULL){ //if the letter is in the middle of the row
                        tmp1->previous->next = tmp1->next;
                        tmp1->next->previous = tmp1->previous;
                    }
                    else if(tmp1->next!=NULL && tmp1->previous==NULL){// if the letter is at the beginning of the row
                        tmp1->next->previous = NULL;
                    }
                    else if(tmp1->next==NULL && tmp1->previous!=NULL){// if the letter is at the end of the row
                        tmp1->previous->next=NULL;
                    }
                    else if(tmp1->next==NULL && tmp1->previous==NULL){// if the letter is at the beginning of the row without any follow letters
                        keyboard[i]==NULL;
                    }
                    tmp1 = tmp1->next; //next pointer
                    delete tmp2; // delete the node;

                }
            }
        }
    }
    //Reset Row and Column to zeros again
    Row = 0;
    Column = 0;
}

void Keyboard::changeLength(int newRow){
    //Change Length of the keyboard
    if(Row!=0 || Column!= 0  ){
        int previousColumn = Column; //hold onto old column
        deleteKeyboard(); //delete the keyboard
        Row=newRow; //set Public Row to the inputed newRow
        Column = previousColumn; //set Public Column to the old column
        createKeyboard(Row,Column); //build the keyboard again
    }
    else{
        cout<<"There are no keys in the keyboard." <<endl;
    }
}
void Keyboard::changeWidth(int newColumn){
    //Change width of keyboard
    if(Row!=0 || Column!= 0  ){
        int previousRow = Row; //hold onto the old row
        deleteKeyboard(); //delete the keyboard
        Row=previousRow; //set Public Row to the old row
        Column = newColumn; //set Public Column to the inputed newCOlumn
        createKeyboard(Row,Column); //build the keyboard again
    }
    else{
        cout<<"There are no keys in the keyboard." <<endl;
    }
}
void Keyboard::rotateKeyboard(){
    //rotate the keyboard 90 degrees
    if(Row!=0 || Column!= 0  ){
        int newRow = Column; //set the newRow equal to the old column
        int newColumn = Row; //set the newColumn equal to the old row
        deleteKeyboard(); //delete the keyboard
        Row = newRow; //set the new row to Public row
        Column = newColumn; //set the new column to Public Column
        createKeyboard(Row,Column); //Create the new keyboard
    }
    else{
        cout<<"There are no keys in the keyboard." <<endl;
    }
}

