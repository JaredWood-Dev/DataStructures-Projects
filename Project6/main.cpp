//Author: Jared Wood
//Due Date: 11/9/22
//Programming Assignment
//Fall 2022 - CS 3358 - 001
//Instructor: Husain Gholoom
//Description:
//To demonstrate understanding and implementation of sort and search algorithms

#include <iostream>
#include <ctime>

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

    

    //Footer
    cout << "November 2022" << endl;
    cout << "Sorting / Searching Benchmark by:" << endl;
    cout << "Jared Wood" << endl;
    return 0;
}
