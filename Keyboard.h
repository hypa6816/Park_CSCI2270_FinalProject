#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

struct Key{
	char letter;
	Key *next;
    Key *previous;

	Key(){};
	Key(char in_letter)
	{
		letter = in_letter;
		next = NULL;
		previous = NULL;
	}

};
// Each Key is a struct with a char letter and pointers for the next and previous key

class Keyboard
{
	public:
		Keyboard();
		~Keyboard();
		// All the functions called from menu. Descriptions are found in README.mt
		void createKeyboard(int row, int column);
		void printKeyboard();
		bool isLetterInKeyboard(std::string letter);
		void wordTraversing(std::string word);
		void wordDirections(std::string word);
		int *findKeyIndex(std::string letter);
		void printIndexes();
		void deleteKeyboard();
		void changeLength(int newRow);
		void changeWidth(int newColumn);
		void rotateKeyboard();
        // There is a public Row and Column that can be manipulated by the main and source cpp files
        // The Row and Column are both initialized to zero to start
		int Row =  0;
		int Column = 0;

	private:
        //Initalizing the array for the first letters in the column 0 for size 100;
		Key* keyboard[100];

};

#endif // KEYBOARD_H
