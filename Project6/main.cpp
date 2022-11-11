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

int quickSortThird(int input[], int left, int right);
//Sorts the array using quicksort and with the pivot being
//the third element of the array

int quickSortThird(char input[], int left, int right);
//Sorts the array using quicksort and with the pivot being
//the third element of the array

void sequentialSearch(char input[], int length, char key);
//Searches through the array for the specified key using sequential search

void binarySearch(char input[], int length, char key);
//Searches throughout the array for the specified key using binary search

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
    const int arraySize = 10000; //TODO: REMOVE FOR TESTING AND SUBMISSION

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
    //Copy the arrays
    for (int i = 0; i < userNum; ++i) {
        tempCharArray[i] = charArray[i];
        tempIntArray[i] = intArray[i];
    }

    //Selection Sort
    cout << "Character array selection sort:" << endl;
    time_t startTime = clock(); //Stores start time
    selectionSort(tempCharArray, userNum);
    time_t endTime = clock(); //Stores end time
    time_t selectChar = difftime(endTime, startTime); //Saves the time for sort
    startTime = clock();
    cout << endl << "Integer array selection sort:" << endl;
    selectionSort(tempIntArray, userNum);
    endTime = clock();
    time_t selectInt = difftime(endTime, startTime); //Saves the time for sort

    //Copy the arrays
    for (int i = 0; i < userNum; ++i) {
        tempCharArray[i] = charArray[i];
        tempIntArray[i] = intArray[i];
    }

    //Quick Sort (Middle element is pivot)
    cout << endl << "Character Array Quick Sort: - Middle Element is "
                    "pivot" << endl;
    startTime = clock(); //Stores the time before running the algr.
    int calls = quickSort(tempCharArray, 0, userNum-1); //Stores the
                        //number of recursive calls that occur during sorting
     endTime = clock(); //Stores the time after running the algr.
    cout << "Start Time:\t" << startTime << endl;
    cout << "End Time:\t" << endTime << endl;
    time_t quickChar = difftime(endTime, startTime); //Stores the time for
                                            //quick sorting the char array
    cout << "Actual CPU Clock time:\t" << quickChar
         << endl;
    cout << "Number of recursive calls: " << calls << endl;
    cout << "Sorted Elements: ";
    display(tempCharArray, userNum);


    cout << endl << "Integer Array Quick Sort: - Middle Element is "
                    "pivot"<< endl;
    startTime = clock();
    calls = quickSort(tempIntArray, 0, userNum-1);
    endTime = clock();
    cout << "Start Time:\t" << startTime << endl;
    cout << "End Time:\t" << endTime << endl;
    time_t quickInt = difftime(endTime, startTime); //Stores the time to quick
                                            //sort the int array
    cout << "Actual CPU Clock time:\t" << quickInt
         << endl;
    cout << "Number of recursive calls: " << calls << endl;
    cout << "Sorted Elements: ";
    display(tempIntArray, userNum);

    //Copy the arrays
    for (int i = 0; i < userNum; ++i) {
        tempCharArray[i] = charArray[i];
        tempIntArray[i] = intArray[i];
    }

    //Quick Sort (3rd element is pivot)
    cout << endl << "Character Array Quick Sort: - 3rd Element is "
                    "pivot" << endl;
    startTime = clock(); //Stores the time before running the algr.
    calls = quickSortThird(tempCharArray, 0, userNum-1); //Stores the
    //number of recursive calls that occur during sorting
    endTime = clock(); //Stores the time after running the algr.
    cout << "Start Time:\t" << startTime << endl;
    cout << "End Time:\t" << endTime << endl;
    time_t quickThirdChar = difftime(endTime, startTime); //Stores the time it
                //take to quick sort the char array with 3rd element as pivot
    cout << "Actual CPU Clock time:\t" << quickThirdChar
         << endl;
    cout << "Number of recursive calls: " << calls << endl;
    cout << "Sorted Elements: ";
    display(tempCharArray, userNum);


    cout << endl << "Integer Array Quick Sort: - 3rd Element is "
                    "pivot"<< endl;
    startTime = clock();
    calls = quickSortThird(tempIntArray, 0, userNum-1);
    endTime = clock();
    cout << "Start Time:\t" << startTime << endl;
    cout << "End Time:\t" << endTime << endl;
    time_t quickThirdInt = difftime(endTime, startTime); //Stores the time it
                    //takes to quick sort the int array with 3rd element as
                    //pivot
    cout << "Actual CPU Clock time:\t" << quickThirdInt << endl;
    cout << "Number of recursive calls: " << calls << endl;
    cout << "Sorted Elements: ";
    display(tempIntArray, userNum);
    cout << endl;

    //Searching for Integer P
    //First sort the char array:
    quickSort(charArray, 0, userNum - 1);

    //Next sequential search / linear search
    startTime = clock();
    sequentialSearch(charArray, userNum, 'P');
    endTime = clock();
    time_t seqSearch = difftime(endTime, startTime); //Stores the time it takes
    //to search using sequential search
    cout << endl;

    //Finally, binary search
    startTime = clock();
    binarySearch(charArray, userNum, 'P');
    endTime = clock();
    time_t binSearch = difftime(endTime, startTime); //Stores the time it takes
    //to search using binary search

    //Final Analysis Output
    cout << endl;
    cout << "Actual CPU Time Summary" << endl;
    cout << "Character Array Size: " << userNum << endl;
    cout << "Selection Sort Time: " << selectChar << endl;
    cout << "Quick Sort Time - Middle Element as Pivot: " << quickChar << endl;
    cout << "Quick Sort Time - 3rd Element as Pivot: " << quickThirdChar <<
    endl;

    cout << endl;
    cout << "Integer Array Size: " << userNum << endl;
    cout << "Selection Sort Time: " << selectInt << endl;
    cout << "Quick Sort Time - Middle Element as Pivot: " << quickInt << endl;
    cout << "Quick Sort Time - 3rd Element as Pivot: " << quickThirdInt <<
    endl;

    cout << endl;
    cout << "Searching for element not in the array: " << endl;
    cout << "Character Array Size: " << userNum << endl;
    cout << "Sequential Search Time: " << seqSearch << endl;
    cout << "Binary Search Time: " << binSearch << endl;


    //Footer
    cout << endl;
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

int quickSortThird(int input[], int left, int right)
{
    int i = left; //Indexing left of the partition
    int j = right; //Indexing right of the partition
    int temp; //Temporary variable for swapping numbers
    int pivot = input[left + 2]; //Determines the location of the
    //pivot - uses 3rd element as pivot
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
//Uses quick sort to sort the elements in the given array, but uses the
//3rd element in the array as the pivot.
//param1: input - The array to be sorted
//param2: left - the left most element in the array
//param3: right - the rightmost element in the array
//return: the number of recursive calls in the array
//-----------------------------------------------------------------------------

int quickSortThird(char input[], int left, int right)
{
    int i = left; //Indexing left of the partition
    int j = right; //Indexing right of the partition
    int temp; //Temporary variable for swapping numbers
    int pivot = input[left + 2]; //Determines the location of the
    //pivot - uses 3rd element as pivot
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
//Uses quick sort to sort the elements in the given array, but uses the
//3rd element in the array as the pivot.
//param1: input - The array to be sorted
//param2: left - the left most element in the array
//param3: right - the rightmost element in the array
//return: the number of recursive calls in the array
//-----------------------------------------------------------------------------

void sequentialSearch(char input[], int length, char key)
{
    int loc = -1; //Stores the location of the key if found
                //-1 represents if the key is not found

    int comparisons = 0; //Stores the number of comparisons
    time_t start = clock(); //Stores the time at the start of searching
    for (int i = 0; i < length; ++i) {
        if (input[i] == key)
        {
            loc = i;
        }
        comparisons++;
    }
    time_t end = clock(); //Stores the time at the end of searching
    if (loc == -1)
    {
        cout << "Char " << key << " was not found." << endl;
    }
    else
    {
        cout << "Found " << key << " at " << loc << endl;
    }
    cout << "Start Time:\t" << start << endl;
    cout << "End Time:\t" << end << endl;
    cout << "Actual CPU Clock Time: " << difftime(end, start) << endl;
    cout << "Total Number of comparisons: " << comparisons << endl;
}
//-----------------------------------------------------------------------------
//Searches the array for the given key using linear/sequential search
//
//param1: input - the array to be searched
//param2: length - the length of the array
//param3: key - the character that the meathod is looking for
//-----------------------------------------------------------------------------

void binarySearch(char input[], int length, char key)
{
    int first = 0; //First element of the array
    int last = length - 1; //Lst element of the array
    int mid; //The middle of the array
    int loc = -1; //Location of the searching element
    int comparisons = 0; //The number of comparisons

    time_t start = clock();
    while (first <= last)
    {
        mid = ( first + last ) / 2; //Getting the middle
        if (input[mid] == key)
        {
            loc = mid;
            break;
        }
        else if (input[mid] > key)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
        comparisons++;
    }

    time_t end = clock();
    if (loc == -1)
    {
        cout << "Char " << key << " was not found." << endl;
    }
    else
    {
        cout << "Found " << key << " at " << loc << endl;
    }
    cout << "Start Time:\t" << start << endl;
    cout << "End Time:\t" << end << endl;
    cout << "Actual CPU Clock Time: " << difftime(end, start) << endl;
    cout << "Total Number of comparisons: " << comparisons << endl;
}
//-----------------------------------------------------------------------------
//Searches the array for the given key using binary search
//
//param1: input - the array to be searched
//param2: length - the length of the array
//param3: key - the character that the meathod is looking for
//-----------------------------------------------------------------------------