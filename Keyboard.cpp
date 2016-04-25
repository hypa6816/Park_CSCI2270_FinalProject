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
            cout<<alphabet;
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
                cout<<alphabet;
                alphabet++;

            }
            cout<<endl;

        }

    }
}

void Keyboard::printKeyboard(){
    for (int i =0; i<Row; i++){
            if(keyboard[i]!=NULL){
                Key *tmp = keyboard[i];
                cout<< tmp->letter<<" ";
                while(tmp->next !=NULL){
                    tmp =tmp ->next;
                    cout<< tmp->letter<<" ";

                }
                cout<<endl;
            }

            else{
                cout<< "empty"<<endl;
            }
        }
}

void Keyboard::wordTraversing(string word){
    //this function will take a word as an input and print the moves to get to each character starting from A or (0,0).
    //The keyboard can only go up and down from the first column of the keyboard and left and right from within the same row.


    Key *current = new Key;
    int current_row = 0;
    int leftClick = 0;
    int rightClick = 0;
    int upClick = 0;
    int downClick =0;


    int wordLength = word.size();
    for(int i=0; i<wordLength; i++){

            bool found = false;

            current_row = 0;
            leftClick = 0;
            rightClick = 0;
            upClick = 0;
            downClick =0;



            if(i==0){
                for(int j=0; j<Row; j++){

                        Key *tmp = keyboard[j];
                        if(tmp->letter != word[i] && tmp->letter + Column < word[i]){
                            rightClick++;
                            while(tmp->next != NULL){
                                //cout<<tmp->letter<<endl;
                                tmp = tmp->next;
                                if(tmp->letter != word[i]){
                                    rightClick++;
                                }
                                else{
                                    found = true;
                                }
                            }
                        }
                        if(tmp->letter != word[i]){
                            downClick++;
                            current = tmp;
                            current_row = j;
                        }

                    }


            }


            else if(i!=0 && current->letter != word[i]){
                if(word[i]>word[i-1]){

                    for(int j=0; j<Row; j++){

                        Key *tmp = keyboard[j];
                        if(tmp->letter != word[i] && tmp->letter + Column < word[i]){
                            rightClick++;
                            while(tmp->next != NULL){
                                //cout<<tmp->letter<<endl;
                                tmp = tmp->next;
                                if(tmp->letter != word[i]){
                                    rightClick++;
                                }
                            }
                        }
                        downClick++;
                        current = tmp;
                        current_row = j;
                    }


                }


                else if(word[i]<word[i-1]){
                    for(int j=current_row; j>0; j--){
                        Key *tmp = keyboard[j];
                        if(tmp->letter != word[i] && tmp->letter - Column < word[i]){
                            leftClick++;
                            while(tmp->previous != NULL){
                                //cout<<tmp->letter<<endl;
                                tmp = tmp -> previous;
                                if(tmp->letter != word[i]){
                                    leftClick++;
                                }
                            }
                        }
                        upClick++;
                        current = tmp;
                        current_row = j;

                }

            }

        }

        if(leftClick==0){
            cout<<word[i]<<": "<<rightClick<<" right clicks"<<endl;
            cout<<word[i]<<": "<<downClick<<" down clicks"<<endl;

        }
        else{
            cout<<word[i]<<": "<<leftClick<<" left clicks"<<endl;
            cout<<word[i]<<": "<<upClick<< " up clicks"<<endl;
        }


    }
}

int * Keyboard::findKeyIndex(string letter){
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
        else if(tmp->letter + Column-1 >letter[0]){
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
