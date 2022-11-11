//Author: Jared Wood
//Due Date: 11/9/22
//Programming Assignment
//Fall 2022 - CS 3358 - 001
//Instructor: Husain Gholoom
//Description:
//To demonstrate understanding and implementation of sort and search algorithms

#include <iostream>
#include <ctime>
#include <chrono>
#include <time.h>

void display(int input[], int length);
//Displays up to 20 elements up the int array

void display(char input[], int length);
//Displays up to 20 elements of the char array

void selectionSort(int input[], int length);
//Sorts the Array using selection sort

void selectionSort(char input[], int length);
//Sorts the Array using selection sort

int quickSort(int input[], int left, int right);
//Sorts the array using quicksort

int quickSort(char input[], int left, int right);
//Sorts the array using quicksort

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

    cout << "Character Array elements are: ";
    display(charArray, userNum);
    cout << "Integer array elements are: ";
    display(intArray, userNum);

    char tempCharArray[arraySize] = {}; //Temporary char array
    // for use in the function
    int tempIntArray[arraySize] = {}; //Temporary int array
    // for use in the function
    for (int i = 0; i < userNum; ++i) {
        tempCharArray[i] = charArray[i];
        tempIntArray[i] = intArray[i];
    }

    cout << "Character array selection sort:" << endl;
    selectionSort(tempCharArray, userNum);
    cout << endl << "Integer array selection sort:" << endl;
    selectionSort(tempIntArray, userNum);

    for (int i = 0; i < userNum; ++i) {
        tempCharArray[i] = charArray[i];
        tempIntArray[i] = intArray[i];
    }



    cout << endl << "Character Array Quick Sort: - Middle Element is"
                    "pivot" << endl;
    time_t startTime = clock(); //Stores the time before running the algr.
    int calls = quickSort(tempCharArray, 0, userNum-1); //Stores the
                        //number of recursive calls that occur during sorting
    time_t endTime = clock(); //Stores the time after running the algr.
    cout << "Start Time:\t" << startTime << endl;
    cout << "End Time:\t" << endTime << endl;
    cout << "Actual CPU Clock time:\t" << difftime(endTime, startTime)
         << endl;
    cout << "Number of recursive calls: " << calls << endl;
    cout << "Sorted Elements: ";
    display(tempCharArray, userNum);


    cout << endl << "Integer Array Quick Sort: - Middle Element is"
                    "pivot"<< endl;
    startTime = clock();
    calls = quickSort(tempIntArray, 0, userNum-1);
    endTime = clock();
    cout << "Start Time:\t" << startTime << endl;
    cout << "End Time:\t" << endTime << endl;
    cout << "Actual CPU Clock time:\t" << difftime(endTime, startTime)
         << endl;
    cout << "Number of recursive calls: " << calls << endl;
    cout << "Sorted Elements: ";
    display(tempIntArray, userNum);


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

void selectionSort(int input[], int length)
{

    int min = 0; //Stores the index of the smallest number for sorting
    int comparisons = 0; //Stores the number of comparisons that occur

    time_t startTime = clock();
    //Stores the initial time before sorting

    //Sorting the array
    for (int i = 0; i < length; ++i) {
        min = i;
        for (int j = i; j < length; ++j) {
            if (input[j] < input[min])
            {
                min = j;
            }
            comparisons++;
        }
        int temp = input[i];
        input[i] = input[min];
        input[min] = temp;
    }

    time_t finalTime = clock();
    //Stores the time after the array
    //has been sorted

    cout << "Start Time:\t" << startTime << endl;
    cout << "End Time:\t" << finalTime << endl;
    cout << "Actual CPU Clock time:\t" << difftime(finalTime, startTime)
    << endl;

    cout << "Total Number of Swaps:\t" << comparisons << endl;

    //Display the elements
    cout << "Sorted Elements: ";
    display(input, length);
}
//-----------------------------------------------------------------------------
//Sorts the given array using selection sort
//
//param1: input[] - the array to be sorted
//param2: length - the length of the array
//-----------------------------------------------------------------------------


void selectionSort(char input[], int length)
{
    int min = 0; //Stores the index of the smallest number for sorting
    int comparisons = 0; //Stores the number of comparisons that occur

    time_t startTime = clock();
    //Stores the initial time before sorting

    //Sorting the array
    for (int i = 0; i < length; ++i) {
        min = i;
        for (int j = i; j < length; ++j) {
            if (input[j] < input[min])
            {
                min = j;
            }
            comparisons++;
        }
        int temp = input[i];
        input[i] = input[min];
        input[min] = temp;
    }

    time_t finalTime = clock();
    //Stores the time after the array
    //has been sorted

    cout << "Start Time:\t" << startTime << endl;
    cout << "End Time:\t" << finalTime << endl;
    cout << "Actual CPU Clock time:\t" << difftime(finalTime, startTime)
    << endl;

    cout << "Total Number of Swaps:\t" << comparisons << endl;

    //Display the elements
    cout << "Sorted Elements: ";
    display(input, length);
}
//-----------------------------------------------------------------------------
//Sorts the given array using selection sort
//
//param1: input[] - the array to be sorted
//param2: length - the length of the array
//-----------------------------------------------------------------------------

int quickSort(int input[], int left, int right)
{
    int i = left; //Indexing left of the partition
    int j = right; //Indexing right of the partition
    int temp; //Temporary variable for swapping numbers
    int pivot = input[(left + right) / 2]; //Determines the location of the
    //pivot
    static int calls = 0; //Stores the number of recursive calls

    while(i <= j)
    {
        //Move the left index right until a value larger than
        // the partition is found
        while (input[i] < pivot)
        {
            i++;
        }
        //Move the right index left until a value less than
        // the partition is found
        while (input[j] > pivot)
        {
            j--;
        }
        //If the 'i' index is less than or equal to the 'j' index
        if (i <= j)
        {
            //Swap the values
            temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            //Move th indexes
            i++;
            j--;
        }
    }

    //Recursion
    //Once both sides have been sorted
    //(Results in [elements] < partition < [elements])
    //Recursively call the function to repeat for each section of the
    //partition
    if (left < j)
    {
        calls++;
        quickSort(input, left, j);
    }
    if (i < right)
    {
        calls++;
        quickSort(input, i, right);
    }
    return calls;
}
//-----------------------------------------------------------------------------
//Uses quick sort to sort the elements in the given array
//
//param1: input - The array to be sorted
//param2: left - the left most element in the array
//param3: right - the rightmost element in the array
//return: the number of recursive calls in the array
//-----------------------------------------------------------------------------

int quickSort(char input[], int left, int right)
{
    int i = left; //Indexing left of the partition
    int j = right; //Indexing right of the partition
    int temp; //Temporary variable for swapping numbers
    int pivot = input[(left + right) / 2]; //Determines the location of the
    //pivot
    static int calls = 0; //Stores the number of recursive calls

    while(i <= j)
    {
        //Move the left index right until a value larger than
        // the partition is found
        while (input[i] < pivot)
        {
            i++;
        }
        //Move the right index left until a value less than
        // the partition is found
        while (input[j] > pivot)
        {
            j--;
        }
        //If the 'i' index is less than or equal to the 'j' index
        if (i <= j)
        {
            //Swap the values
            temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            //Move th indexes
            i++;
            j--;
        }
    }

    //Recursion
    //Once both sides have been sorted
    //(Results in [elements] < partition < [elements])
    //Recursively call the function to repeat for each section of the
    //partition
    if (left < j)
    {
        calls++;
        quickSort(input, left, j);
    }
    if (i < right)
    {
        calls++;
        quickSort(input, i, right);
    }
    return calls;
}
//-----------------------------------------------------------------------------
//Uses quick sort to sort the elements in the given array
//
//param1: input - The array to be sorted
//param2: left - the left most element in the array
//param3: right - the rightmost element in the array
//return: the number of recursive calls in the array
//-----------------------------------------------------------------------------