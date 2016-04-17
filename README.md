# Park_CSCI2270_FinalProject


Sara Hyo Park 103387397
CSCI 2270 
Final Project Description

  This project will implement an imaginary keyboard. This keyboard is made up of alpha letters and its size is inputed by the user.
For example if the size inputed was 5(r) x 3(c), then its indexes would be:

A B C

D E F

G H I

J K L

M N O

  After the keyboard is created, the application will print the keyboard and then, prompt the user to input a word utlilizing these
letters such as "HELLO". The application will then start from A or (0,0) and traverse through the keyboard to find the letters 
needed to complete the word. For each letter is found, the computer will print out the commands need to obtain the letter for example,
from the keyboard above if "H" was need, the application will print:

"H", down 2 click and right 1 click.

  This project will be implemented using double linked lists for the keyboard, and hash tables to store the reached data.
