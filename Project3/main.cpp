//Author: Jared Wood
//
//Serial Number: 51
//
//Due Date: 9-23-22
//Programming Assignment Number 3
//Fall 2022 - CS 3358 - Section 001
//
//Instructor Husain Gholoom
//
//Description:
//This program is to demonstrate understanding and knowledge of how to create
//and utilize classes in C++.

//TODO: ADHERE TO STYLE GUIDELINES

#include <iostream>
#include <cmath>

using namespace std;

class myInt
{
    private:
        int userNumber; //Stores the user's Number
                        //Must be >= 6
    public:
        int getInt();
        //Returns the userNumber
        void setInt(int num);
        //Sets the userNumber to the parameter
        bool isMultiple(int multiplier);
        //Checks if userNum is divisible by the given parameter
        bool sumIsEven();
        //Checks if userNumber is even
        double getSquareRoot();
        //Calculates the square root of userNumber
        bool isPrime();
        //Checks if userNumber is prime
        bool isPerfect();
        //Checks if userNumber is a perfect number
        myInt();
        //Default constructor, sets userNum to 0
};
//------------------------------------
//Class: MyInt
//Purpose: To create and manipulate an integer
//to provide desired output for the user.
//
//Private:
//userNumber
//
//Public:
//getInt()
//setInt()
//isMultiple()
//sumIsEven()
//getSquareRoot()
//isPrime()
//isPerfect()
//myInt() - Default Constructor
//------------------------------------
int main() {

    //Program Header; defines what the program will do
    cout << "Welcome to Integer Manipulation Program" << endl;
    cout << "The purpose of this program is to:" << endl;
    cout << "-Get an integer as input" << endl;
    cout << "-Determine if 7,11,13 is a multiple of the integer" << endl;
    cout << "-Checks if the sum of the integer's digits are even" << endl;
    cout << "-Finds the Square Root of the integer" << endl;
    cout << "-Checks if the integer is prime and perfect" << endl;

    //This loops allows the program to be repeated
    while(true)
    {
        cout << "Would you like to run the program?" << endl;
        string input; //Variable used for checking if user wishes to continue
                        //The Program; y = yes, n = no
        cin >> input;

        //Ensures valid input
        if (input == "no" || input == "NO" || input == "n" || input == "N")
        {
            break;
        }
        if (input == "yes" || input == "YES" || input == "y" || input == "yes")
        {
            while (true)
            {
                int intInput = 0; //Variable to store user's number
                                    //Must be >= 6
                cout << "Enter an integer: " << endl;
                cin >> intInput;

                //Ensures Valid number input
                if (intInput < 6)
                {
                    cout << "Invalid Input! Number must be => 6!" << endl;
                }
                if (intInput >= 6)
                {
                    //Creates the integer object
                    myInt num;
                    num.setInt(intInput);

                    //Checks if number is a multiple of 7,11, and 13
                    cout << "I.\t" << intInput << " is ";
                    if (num.isMultiple(7))
                    {
                        cout << "a multiple of 7, ";
                    }
                    if (!num.isMultiple(7))
                    {
                        cout << "not a multiple of 7, ";
                    }
                    if (num.isMultiple(11))
                    {
                        cout << "a multiple of 11, ";
                    }
                    if (!num.isMultiple(11))
                    {
                        cout << "not a multiple of 11, ";
                    }
                    if (num.isMultiple(13))
                    {
                        cout << "a multiple of 13." << endl;
                    }
                    if (!num.isMultiple(13))
                    {
                        cout << "not a multiple of 13." << endl;
                    }

                    //Checks the sum of the digits
                    cout << "II.\t" << "The sum of its digits is ";
                    if (num.sumIsEven())
                    {
                        cout << "even." << endl;
                    }
                    if (!num.sumIsEven())
                    {
                        cout << "odd. " << endl;
                    }

                    //Gets the square root
                    cout << "III.\tSquare root of " << intInput << " is " <<
                    num.getSquareRoot() << endl;

                    //Checks if the number is a prime number
                    cout << "IV.\t" << intInput << " is ";
                    if (num.isPrime())
                    {
                        cout << "a prime number." << endl;
                    }
                    if (!num.isPrime())
                    {
                        cout << "not a prime number." << endl;
                    }

                    //Checks if the number is a perfect number
                    cout << "V.\t" << intInput << " is ";
                    if (num.isPerfect())
                    {
                        cout << "a perfect number." << endl;
                    }
                    if (!num.isPerfect())
                    {
                        cout << "not a perfect number." << endl;
                    }
                    break;
                }
            }
        }
        else
        {
            cout << "Invalid Input! Input must be Y for yes or N for no.\n";
        }
    }

    //Program footer
    cout << "This program is implemented by Jared Wood" << endl;
    cout << "9-26-22" << endl;
    return 0;
}
int myInt::getInt()
{
    return userNumber;
}
//-----------------------------------
//Gets the value stored in userNumber
//-----------------------------------
void myInt::setInt(int num)
{
    userNumber = num;
}
//---------------------------------------------
//Sets the value of userNumber to the parameter
//
//Param1: int num - user input number
//---------------------------------------------
bool myInt::isMultiple(int multiplier)
{
    if (userNumber % multiplier == 0)
    {
        return true;
    }
    return false;
}
//------------------------------------------------------------
//Determines if userInt is divisible by the given parameter
//
//Param 1: int multiplier - to check if userNum is divisible by
//------------------------------------------------------------
bool myInt::sumIsEven()
{
    int sumNum = 0; //Stores the sum of the digits
    int tempNum = userNumber; //Stores the userNumber for manipulation
    while (tempNum > 0)
    {
        int digit = tempNum % 10;
        tempNum = tempNum / 10;
        sumNum = sumNum + digit;
    }
    if (sumNum % 2 == 0)
    {
        return true;
    }
    return false;
}
//----------------------------------------------------------------
//Checks if the sum of the digits of userNum is even
//----------------------------------------------------------------
double myInt::getSquareRoot()
{
    return pow(userNumber, 0.5);
}
//-------------------------------------
//Return the square root of userNumber
//-------------------------------------
bool myInt::isPrime()
{
    int multCount = 0; //Stores the number of numbers divisible by userNumber
    for (int i = 1; i <= userNumber; i++) {
        if (userNumber % i == 0)
        {
            multCount++;
        }
    }
    if (multCount > 2)
    {
        return false;
    }
    return true;
}
//-----------------------------------------------
//Checks if userNumber is a prime number
//-----------------------------------------------
bool myInt::isPerfect()
{
    int perfectCount = 0; //Stores the total value of multiples for finding
                            //the perfect number.
    for (int i = 1; i < userNumber; ++i) {
        if (userNumber % i == 0)
        {
            perfectCount = perfectCount + i;
        }
    }
    if (perfectCount == userNumber)
    {
        return true;
    }
    return false;
}
//---------------------------------------------
//Checks if userNumber is a perfect number.
//---------------------------------------------
myInt::myInt()
{
    userNumber = 0;
}
//-----------------------------------------------------------------
//Default Constructor: Sets userNumber to zero if no input is given
//-----------------------------------------------------------------
