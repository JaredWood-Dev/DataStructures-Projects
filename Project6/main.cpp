//Author: Jared Wood
//Due Date: 11/9/22
//Programming Assignment
//Fall 2022 - CS 3358 - 001
//Instructor: Husain Gholoom
//Description:
//To demonstrate understanding and implementation of sort and search algorithms

#include <iostream>
#include <ctime>

void display(int input[], int length);
//Displays up to 20 elements up the int array

void display(char input[], int length);
//Displays up to 20 elements of the char array

using namespace std;
int main() {

    //Seeded Random using Time
    srand(time(0));

    //Header
    cout << "Searching and Sorting Benchmark" << endl;

    //Get user input and create an array of length n
    int userNum = 0; //Gets and stores the user's input, used for
                        //array creation
    cout << "Enter the size of the array: " << endl;
    cin >> userNum;
    if (userNum < 9)
    {
        cout << "*** Error - Invalid Input - Size must be > 9 ***" << endl;
    }
    const int arraySize = 10; //TODO: REMOVE FOR TESTING AND SUBMISSION

    //Create the arrays
    char charArray[arraySize] = {}; //TODO
    int intArray[arraySize] = {}; //TODO

    //Populate the arrays
    for (int i = 0; i < userNum; ++i) {
        charArray[i] = rand() % 26 + 97;
        intArray[i] = rand() % 25 + 1;
    }

    display(charArray, userNum);
    display(intArray, userNum);


    //Footer
    cout << "November 2022" << endl;
    cout << "Sorting / Searching Benchmark by:" << endl;
    cout << "Jared Wood" << endl;
    return 0;
}

void display(int input[], int length)
{

    //Check if it is greater than 20
    if (length > 20)
    {
        length = 20;
    }

    cout << "Integer array elements are: ";
    //Loop through up to the first 20 elements, and display them
    for (int i = 0; i < length; ++i) {
        cout << input[i] << " ";
    }
    cout << endl;
}
//-----------------------------------------------------------------------------
//Displays the first 20 elements of the array.
//
//param1: input - The array to be displayed
//param2: length - The length of the array
//-----------------------------------------------------------------------------

void display(char input[], int length)
{

    //Check if it is greater than 20
    if (length > 20)
    {
        length = 20;
    }

    cout << "Character Array elements are: ";
    //Loop through up to the first 20 elements, and display them
    for (int i = 0; i < length; ++i) {
        cout << input[i] << " ";
    }
    cout << endl;
}
//-----------------------------------------------------------------------------
//Displays the first 20 elements of the array.
//
//param1: input - The array to be displayed
//param2: length - The length of the array
//-----------------------------------------------------------------------------