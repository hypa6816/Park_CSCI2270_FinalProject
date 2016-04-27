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

class Keyboard
{
	public:
		Keyboard();
		~Keyboard();
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

		int Row =  0;
		int Column = 0;
	private:

		int keyboardSize;
		Key* keyboard[100];

};

#endif // KEYBOARD_H
