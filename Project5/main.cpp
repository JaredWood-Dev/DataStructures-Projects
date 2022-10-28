#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

void reverseDisplay(int inputArray[], int index);
//Takes an input array and recursively displays it in reserve

int pow(int input, int power);
//Takes a value and the power to raise it to and recursively calculates the
// result

void displayPows(int input, int end);
//Displays a table of values from 1 to n, with n being the first element in
//the array, and the square of each number.

int main()
{
    srand(time(0));

    //Introduction to the application
    cout << "*** Welcome to My APP ***" << endl;

    //Get Size of the Array, store it in a variable
    int arraySize = 0; //userInput stores what size of the array
    const int ClionArraySize = 10; //TODO: REMOVE FOR SUBMISSION AND TESTING
    cout << "Enter the Array size. ( Must be  >= 5 and <= 20 ) -> ";
    cin >> arraySize;
    cout << endl;

    //Checks to ensure that the size of the array is within the bounds
    if (arraySize < 5 || arraySize > 20)
    {
        cout << "Invalid array size. ( Must be >= 5 and <= 20 )." << endl;
    }
    else
    {
        //Creating the Array and populate it with elements
        cout << "The generated array is : ";
        int userArray[ClionArraySize]; //TODO
        for (int i = 0; i < arraySize; ++i) {
            userArray[i] = rand() % 479 + 21;
            cout << userArray[i] << " ";
        }

        cout << endl << "The Reversed Array is: ";
        reverseDisplay(userArray, arraySize);
        cout << endl;

        cout << userArray[arraySize - 1] << " raised to the 2nd power is: ";
        cout << pow(userArray[arraySize - 1], 2);
        cout << endl;

        cout << "Table of square values 1 - " << userArray[0] << endl;
        cout << "N\tN Squared" << endl;
        displayPows(1, userArray[0]);

    }

    cout << endl;
    cout << "Jared Wood - Programmer \n October 2022" << endl;

}

void reverseDisplay(int inputArray[], int index)
{
    //Print value at index
    cout << inputArray[index - 1] << " ";

    //Edge case, terminates recursion when the entire loop is completed
    if (index == 1)
    {
        return;
    }
    index--;
    reverseDisplay(inputArray, index);
}
//-----------------------------------------------------------------------------
//Description: Takes and input array and recursively displays the array
//backwards.
//
//param1: inputArray - The array to be sorted.
//param2: index - used for indexing throughout the array.
//return: returns to signify when terminate the recursion.
//-----------------------------------------------------------------------------

int pow(int input, int power)
{
    //Every call of pow() multiplies input by itself.
    if (power == 1)
    {
        return input;
    }
    power--;
    pow(input * input, power);
}
//-----------------------------------------------------------------------------
//Description: Takes an input number and raises it to the power given
//
//param1: input - the number to raised.
//param2: power - the number of how many times to multiply the input by itself
//return: The result of the math operation
//-----------------------------------------------------------------------------

void displayPows(int input, int end)
{
    if (input == end)
    {
        return;
    }
    cout << input << "\t" << pow(input, 2) << endl;
    input++;
    displayPows(input, end);
}
//-----------------------------------------------------------------------------
//Description: Creates a table containing numbers from 1 to the input value,
//and the square of those numbers.
//
//param1: input - the begging of the table, typically 1.
//param2: end - the end of the table, the first element of the array
//return: terminates the recursion
//-----------------------------------------------------------------------------

