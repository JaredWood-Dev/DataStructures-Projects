//Author: Jared Wood
//
//Serial Number: 51
//
//Due Date: October 31, 2022
//Programming Assignment Number 5
//
//Fall 2022 - CS 3358 - 001
//
//Instructor: Husain Gholoom
//
//Description: To demonstrate knowledge and understanding of
// recursive algorithms

#include <cstdlib>
#include <iostream>
#include <ctime>
//TODO: Adhere to style guidelines,
using namespace std;

void reverseDisplay(int inputArray[], int index);
//Takes an input array and recursively displays it in reserve

int pow(int input, int power);
//Takes a value and the power to raise it to and recursively calculates the
// result

void displayPows(int input, int end);
//Displays a table of values from 1 to n, with n being the first element in
//the array, and the square of each number.

void vertDisplay(int input);
//Displays the number inputted vertically, one digit at a time

bool isIncreasing(int input);
//Checks if the digits of a number are increasing.

int reverse(int input);
//Reverses the digits of a number.

bool isPrime(int input, int mult);
//Determines if the number given is prime.

int main()
{
    srand(time(0));

    //Introduction to the application
    cout << "*** Welcome to My APP ***" << endl;

    //Get Size of the Array, store it in a variable
    int arraySize = 0; //userInput stores what size of the array
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
        int userArray[arraySize];
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
        cout << endl;

        cout << userArray[1] << " vertically: " << endl;
        vertDisplay(userArray[1]);
        cout << endl;

        cout << userArray[2] << " is ";
        if(!isIncreasing(userArray[2]))
        {
            cout << "not ";
        }
        cout << "in increasing order" << endl;

        cout << "The reversed of " << userArray[3] << " is " <<
        reverse(userArray[3]) << endl;


        cout << userArray[4] << " is ";
        if (!isPrime(userArray[4],1))
        {
            cout << "not ";
        }
        cout << "Prime" << endl;

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

void vertDisplay(int input)
{
    if (input == 0)
    {
        return;
    }
    int num = input % 10; //Variable used for storing calculations
    input = (input - num) / 10;
    vertDisplay(input);
    cout << num << endl;
}
//-----------------------------------------------------------------------------
//Description: Displays each digit of an input number separately
//
//param1: input - number to display vertically
//return: terminates the recursion
//-----------------------------------------------------------------------------

bool isIncreasing(int input)
{
    int num = input % 10;
    input = (input - num) / 10;
    int num2 = input % 10;
    if(num2 < num)
    {
        if (input < 10 || isIncreasing(input))
        {
            return true;
        }

    }
    return false;
}
//-----------------------------------------------------------------------------
//Description: Takes an integer as input and determines weather its digits
//are increasing or not.
//
//param1: input - the integer input to be checked.
//output: returns true if the digits are increasing, false otherwise
//-----------------------------------------------------------------------------

int reverse(int input)
{
    //Variables to store the place of the digit and the total number to return
    static int total = 0; //Stores the number to return
    static int magnitude = 1; //Stores the current position of the digit

    //Loops if there is still value present to be reversed.
    if (input > 0){

        //Recurse to the largest digit in the number
        reverse(input / 10);

        //Add the digit to the new number, multiply by what magnitude it is
        total = total + ( input % 10) * magnitude;

        //Increase magnitude after every iteration to have 1s, 10s, 100s, etc
        magnitude = magnitude * 10;
    }

    //Return the final amount
    return total;
}
//-----------------------------------------------------------------------------
//Description: Reverses the digits in the inputted number
//
//param1: input - the number to be reversed
//output: the reversed number
//-----------------------------------------------------------------------------

bool isPrime(int input, int mult)
{
    static int solutions = 0; //Stores how many mays there are to divide input

    //If size 1 or if all combinations have been tried, terminate
    if (mult == input)
    {
        return false;
    }

    //If mult successfully divides input
    if (input % mult == 0)
    {
        solutions++;
    }

    //Recursively check every combination
    mult++;
    isPrime(input, mult);

    //Determine if prime or not
    if (solutions > 2)
    {
        return false;
    }
    return true;
}
//-----------------------------------------------------------------------------
//Description: Determines if the given number is prime or not
//
//param1: input - the number to check if it is prime
//param2: mult - keeps track of what number is dividing input
//output: termination conditions and if the number is prime or not
//true = prime, false = not prime
//-----------------------------------------------------------------------------