#include "Keyboard.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stdlib.h>


using namespace std;

int main()
{
    Keyboard KB;
    //Start up the menu
    int option = 0;
    do
    {
        cout << "======Main Menu======" << endl;
        cout << "1. Create Keyboard" << endl;
        cout << "2. Print Keyboard" << endl;
        cout << "3. Directions to Type a Word" << endl;
        cout << "4. Find and Print the Key Index" << endl;
        cout << "5. Print all indexes of Keyboard" <<endl;
        cout << "6. Check if a Letter is in the Keyboard" << endl;
        cout << "7. Change length of Keyboard" << endl;
        cout << "8. Change width of Keyboard" << endl;
        cout << "9. Rotate the Keyboard" <<endl;
        cout << "10. Delete the Keyboard" <<endl;
        cout << "11. Quit" << endl;
        cin >> option
        ;
        cin.ignore();
        switch(option)
        {

        case 1:
        {
            //Create The Keyboard

            string rowString;
            string columnString;
            cout<< "Enter the length of the keyboard:" <<endl;
            getline(cin,rowString);
            cin.ignore();
            cout<< "Enter the width of the keyboard:" <<endl;
            getline(cin,columnString);
            cin.ignore();
            //converting into integer
            KB.Row = atoi(rowString.c_str());
            KB.Column = atoi(columnString.c_str());
            KB.createKeyboard(KB.Row,KB.Column);


            break;
        }

        case 2:
        {
            //print
            KB.printKeyboard();

            break;
        }

        case 3:
        {   //Word Directions
            string word;
            cout<< "Please enter a word (in CAPS): "<<endl;
            getline(cin, word);
            cin.ignore();
            KB.wordDirections(word);

            break;
        }
        case 4:
        {   //Find the letter's index
            string letter;
            cout<< "Please enter a letter (in CAPS): "<<endl;
            getline(cin, letter);
            cin.ignore();
            int *index; //index is a pointer to an array
            index = KB.findKeyIndex(letter);
            int row = *(index+0); //row is the first
            int column = *(index+1);
            cout<< "The row of letter, "<<letter<< " is " <<row<<endl;
            cout<< "The column of letter, "<<letter<< " is " <<column<<endl;
            break;
        }
        case 5:
        {
            //print all indexes of the keys
            KB.printIndexes();
            break;
        }
        case 6:
        {

            //check if letter is in the keyboard
            string letter;
            bool found;
            cout<< "Please enter a letter (in CAPS): "<<endl;
            getline(cin, letter);
            cin.ignore();
            found = KB.isLetterInKeyboard(letter);
            if(found==true){
                cout<<"The letter is in the keyboard."<<endl;
            }
            else{
                cout<<"The letter is not in the keyboard."<<endl;
            }
            break;
        }
        case 7:
        {
            //Change length of keyboard
            string newRowString;
            cout<< "Please enter the new length of the keyboard: "<<endl;
            getline(cin, newRowString);
            int newRow = atoi(newRowString.c_str());
            KB.changeLength(newRow);

            break;
        }
        case 8:
        {
            //Change width of keyboard
            string newColumnString;
            cout<< "Please enter the new width of the keyboard: "<<endl;
            getline(cin, newColumnString);
            int newColumn = atoi(newColumnString.c_str());
            KB.changeWidth(newColumn);
            break;
        }
        case 9:
        {
            //Rotate Keyboard
            KB.rotateKeyboard();
            break;
        }
        case 10:
        {
            //Delete Keyboard
            KB.deleteKeyboard();
            break;
        }

        case 11:
        {
            //Quit
            cout << "Goodbye!" << endl;
            break;
        }
        }
    }
    while(option!=11);
}

