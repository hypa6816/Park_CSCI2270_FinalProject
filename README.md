# Park_CSCI2270_FinalProject


Sara Hyo Park 103387397
CSCI 2270 Data Structures
-------------------------------------------------------------------------------------------------------------------------------
Final Project Description

  This project will implement an imaginary keyboard. This keyboard is made up of alpha letters and its size is inputed by the user.
For example if the size inputed was 5(r) x 3(c), then the keyboard would be:

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

  This project will be implemented using double linked lists for the keyboard, and an allocated hash tables to store the reached data.
  
-------------------------------------------------------------------------------------------------------------------------------

How to Run:

  1. Download all files
  2. Place all files in the same folder. 
  3. Run the main function and start up the menu function
  4. Choose an option.
    There are 11 options:
      1. Create Keyboard: This option will ask user for a length and column to size the keyboard and input letters in.
      2. Print Keyboard: This option will print the letters in the keyboard.
      3. Directions to a word: This option will ask user for a word then the application will look for each letter in the word     and print the directions to each letter in the word. For example if the word was HELLO and the keyboard was the            keyboard in the project description the application will print:
    
            H: 1 right click and 2 down click

            E: 1 up click
            
            L: 1 right click and 2 down click
            
            L: No movement necessary
            
            O: 1 down click
            
      4. Find and Print Letter index: This option will ask user for a letter then the application will look for the letter and     print the index of that letter for example: for the letter A: (0,0)
      5. Print all indexes of the keyboard: This option will print all the indexes of the keyboard. For example for the            keyboard in the project desciption, the application will print:
    
            (0,0) (0,1) (0,2)

            (1,0) (1,1) (1,2)
            
            (2,0) (2,1) (2,2)
            
            (3,0) (3,1) (3,2)
            
            (4,0) (4,1) (4,2)
            
      6. Check if letter is in the keyboard: This option will ask user for a letter to check if it is in the keyboard
      7. Change length of keyboard: This option will ask user for a new keyboard length and make the keyboard that new length.
      8. Change width of keyboard: This option will ask user of a new keyboard width and make the keyboard that new width.
      9. Rotate keyboard: This option will rotate the keyboard 90 degrees. For example for the keyboard in the description:
      
            A B C D E F
            
            G H I J K L
            
            M N O P Q R
            
      10. Delete keyboard: This option will delete the keyboard
      11. Quit: This option will quit the application
            
            
  ***(For any option with cin you may have to press enter twice after your input depending on your operating system)***

-------------------------------------------------------------------------------------------------------------------------------
Dependencies:
  There are no dependencies for this application.
-------------------------------------------------------------------------------------------------------------------------------
System Requirements:
  Though this application was created for windows, it should have no problem running on a Mac or a Linux 
-------------------------------------------------------------------------------------------------------------------------------
