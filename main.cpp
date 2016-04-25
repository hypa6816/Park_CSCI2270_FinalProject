#include "Keyboard.h"
#include <iostream>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>


using namespace std;

int main()
{
    Keyboard KB;
    //Making Menu
    int option = 0;
    do
    {
        cout << "======Main Menu======" << endl;
        cout << "1. Create Keyboard" << endl;
        cout << "2. Print Keyboard" << endl;
        cout << "3. Word Input Traversing" << endl;
        cout << "4. Find and Print the Key Index" << endl;
        cout << "5. Quit" << endl;
        cin >> option
        ;
        cin.ignore();
        switch(option)
        {

        case 1:
        {
            //Create The Keyboard

            string row1;
            string column1;
            cout<< "Enter the length of the keyboard:" <<endl;
            getline(cin,row1);
            cin.ignore();
            cout<< "Enter the width of the keyboard:" <<endl;
            getline(cin,column1);
            cin.ignore();
            KB.Row = atoi(row1.c_str());
            KB.Column = atoi(column1.c_str());
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
        {
            string word;
            cout<< "Please enter a word (in CAPS): "<<endl;
            getline(cin, word);
            cin.ignore();
            KB.wordTraversing(word);

            break;
        }
        case 4:
        {
            string letter;
            cout<< "Please enter a letter (in CAPS): "<<endl;
            getline(cin, letter);
            cin.ignore();
            int *index;
            index = KB.findKeyIndex(letter);
            int row = *(index+0);
            int column = *(index+1);
            cout<< "The row of letter, "<<letter<< " is " <<row<<endl;
            cout<< "The column of letter, "<<letter<< " is " <<column<<endl;
            break;
        }
        case 5:
        {
            //Quit
            cout << "Goodbye!" << endl;
            break;
        }
        }
    }
    while(option!=5);
}

