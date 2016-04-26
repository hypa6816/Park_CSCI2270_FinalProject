#include "Keyboard.h"
#include <iostream>
#include <vector>
#include <fstream>
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
}

void Keyboard::createKeyboard(int row, int column){


    char alphabet = 'A';



    for(int i=0; i<row;i++){
        Key *node = new Key;
        node->letter = NULL;
        node->next=NULL;
        node->previous=NULL;
        if(alphabet<'Z'){
            node->letter = alphabet;
            keyboard[i]= node;
            alphabet++;
            Key *tmp = keyboard[i];

            for(int j=0; j<column-1;j++){

                Key *Next = new Key;
                Next->letter = NULL;
                Next->next = NULL;
                node->next = Next;
                Next->previous = node;
                node = node->next;
                node->letter = alphabet;
                tmp->next = node;
                node->previous = tmp;

                node->next = NULL;
                tmp = tmp->next;
                alphabet++;

            }
            cout<<endl;

        }
        else{
            //letter is greater than Z (i.e. does not exist)
            node->letter =NULL;
            keyboard[i]=node;
            Key *tmp = keyboard [i];
            for(int j=0; j<column-1;j++){

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
    for (int i =0; i<Row; i++){
            if(keyboard[i]!=NULL){
                Key *tmp = keyboard[i];

                while(tmp->next !=NULL){
                    if(tmp->letter!=NULL){

                        cout<< tmp->letter<<"     ";
                    }
                    else {
                        cout<<"NULL"<<" ";
                    }
                    tmp =tmp ->next;



                }
                cout<<endl<<endl;

            }

            else{
                cout<< "empty row"<<endl;
            }
        }
}

bool Keyboard::isLetterInKeyboard(string letter){
    bool found = false;
    for (int i =0; i<Row; i++){
            if(keyboard[i]!=NULL){
                Key *tmp = keyboard[i];
                if(tmp->letter==letter[0]){
                    found = true;
                }
                while(tmp->next !=NULL){
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

    int leftClick = 0;
    int rightClick = 0;
    int upClick = 0;
    int downClick =0;

    int *index_current;
    int *index_previous;

    int wordLength = word.size();

    for(int i =0; i<wordLength; i++){
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



        if(i==0){
            index_current = findKeyIndex(letter_current);
            downClick = *(index_current+0);
            rightClick = *(index_current+1);
            cout<<word[i]<<": "<<rightClick<<" right clicks";
            cout<<" and "<<downClick<<" down clicks"<<endl;
        }
        else if(i!=0){

            index_current = findKeyIndex(letter_current);
            index_previous = findKeyIndex(letter_previous);

            if(*(index_current+0)-*(index_previous+0)>0 && *(index_current+1)-*(index_previous+1)>0 ){
                //if movement is right and down
                downClick = *(index_current+0)-*(index_previous+0);
                rightClick = *(index_current+1)-*(index_previous+1);
                cout<<word[i]<<": "<<rightClick<<" right clicks";
                cout<<" and "<<downClick<<" down clicks"<<endl;

            }

            else if(*(index_current+0)-*(index_previous+0)>0 && *(index_current+1)-*(index_previous+1)<0 ){
                //if movement is left and down
                downClick = *(index_current+0)-*(index_previous+0);
                leftClick = *(index_previous+1)-*(index_current+1);
                cout<<word[i]<<": "<<leftClick<<" left clicks";
                cout<<" and "<<downClick<<" down clicks"<<endl;

            }
            else if(*(index_current+0)-*(index_previous+0)<0 && *(index_current+1)-*(index_previous+1)<0){
                //if movement is left and up
                upClick = *(index_previous+0)-*(index_current+0);
                leftClick = *(index_previous+1)-*(index_current+1);
                cout<<word[i]<<": "<<leftClick<<" left clicks";
                cout<<" and "<<upClick<<" up clicks"<<endl;
            }

            else if(*(index_current+0)-*(index_previous+0)<0 && *(index_current+1)-*(index_previous+1)>0){
                //if movement is right and up
                upClick = *(index_previous+0)-*(index_current+0);
                rightClick = *(index_current+1)-*(index_previous+1);
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

            if(tmp->letter== letter[0]){
                found_row = true;
            }
            else if(tmp->letter + Column-1 >=letter[0]){
                found_row = true;
            }
            else if(tmp->letter +Column-1 < letter[0]){
                found_row = false;
                row++;
            }
        }
        //now finding column
        tmp = keyboard[row];
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
        index[0] = row;
        index[1] = column;

        return index;
    }

}
