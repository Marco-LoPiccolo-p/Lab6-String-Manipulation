// MarcoLoPiccolo_Lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*Write a program that accepts a C-string input from the user and reverses the contents of the string.
Your program should work by using two pointers. The "head" pointer should be set to the address of the last character in the string, 
and the "tail" pointer should be set to the address of the last character in the string(i.e.,the character before the terminating null).
The program should swap the characters referenced by the pointers, increment "head" to point to the next character , decrement "tail" to point to the
second-to-last character, and so on, until all characters have been swapped and the entire string reversed.*/

#include <iostream>
#include <cstring>                          //used for C-string manipulation
using namespace std;

void reverseWord(char inputString[]);           //Function Header for reversing the string

int main()
{
    const int sentenceSize = 100;          //sets the size of the string to 100 which in most cases is large enough but can be changed to larger hence it is its own variable so that rest of code doesn't need change
    char normWord[sentenceSize];         //initializes the C-String of normWord using the sentence size variable

    cout << "Please Enter a Sentence or Word" << endl;   //Prompts user to enter a sentence or word
    cin.getline(normWord, sentenceSize);                  //uses getline for C-string to account for possible whitespace used

    reverseWord(normWord);                         //Calls reverse word function

    cout << "The Sentence or Word in Reverse is" << endl;   //Shows the newly reversed word or phrase
    cout << normWord;


    system("Pause");
    return 0;
}

//Function reverse word is meant to reverse the order of a string or phrase with void so that it does not return any value with the 
//input parameter of the input C-string which since it is an array it doesn't need to have the & operator for it to be pass by reference to main function
//so the changing of the C-string will change the value in main
void reverseWord(char inputString[]) {   
    char* head;                        //initializes the pointer of head which will be used for the beginning of the string
    char* tail;                        //initializes the pointer of tail which will be used for the end of the string
    char tempPlace;                    //temp place is a normal char value which will be used to store values in the string so that each value can be changed correctly

    head = inputString;              //assigns both pointers to the address of the first value of the C-string
    tail = inputString;

    for (int i = 0; i < strlen(inputString) - 1; i++) {  //for loop uses the length of the C-string minus 1 so that the tail pointer can point to the last value in the C-string array
        tail++;                                           //by incrementing the pointer within the for loop
    }

    for (int i = 0; i < strlen(inputString) / 2; i++) {  //for loop used again so that it goes through the string and stops half way through the string length so that it doesn't go through the second half
        tempPlace = *tail;                       //sets the value that tail points to as tempplace
        *tail = *head;                           //then changes the value that tail points to as the first value in the array by setting the value that head points to to the tail value
        *head = tempPlace;                       //the value that head points to then is changed to the tempplace value which was the original value that tail pointed to which then reverses those numbers

        head++;                               //increments to the next address value in the array of the C-string
        tail--;                              //decrements to the next address value in the array of the C-string
    }


}
