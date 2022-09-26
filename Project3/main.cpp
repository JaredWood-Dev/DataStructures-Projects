#include <iostream>
#include <cmath>

using namespace std;

class myInt
{
    private:
        int userNumber;
    public:
        int getInt();
        void setInt(int num);
        bool isMultiple(int multiplier);
        bool sumIsEven();
        double getSquareRoot();
        bool isPrime();
        bool isPerfect();
        myInt();
};
int main() {

    cout << "Welcome to Integer Manipulation Program" << endl;
    cout << "The purpose of this program is to:" << endl;
    cout << "-Get an integer as input" << endl;
    cout << "-Determine if 7,11,13 is a multiple of the integer" << endl;
    cout << "-Checks if the sum of the integer's digits are even" << endl;
    cout << "-Finds the Square Root of the integer" << endl;
    cout << "-Checks if the integer is prime and perfect" << endl;

    while(true)
    {
        cout << "Would you like to run the program?" << endl;
        string input;
        cin >> input;
        if (input == "no" || input == "NO" || input == "n" || input == "N")
        {
            break;
        }
        if (input == "yes" || input == "YES" || input == "y" || input == "yes")
        {
            while (true)
            {
                int intInput = 0;
                cout << "Enter an integer: " << endl;
                cin >> intInput;
                if (intInput < 6)
                {
                    cout << "Invalid Input! Number must be => 6!" << endl;
                }
                if (intInput >= 6)
                {
                    myInt num;
                    num.setInt(intInput);
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


                    cout << "II.\t" << "The sum of its digits is ";
                    if (num.sumIsEven())
                    {
                        cout << "even." << endl;
                    }
                    if (!num.sumIsEven())
                    {
                        cout << "odd. " << endl;
                    }

                    cout << "III.\tSquare root of " << intInput << " is " <<
                    num.getSquareRoot() << endl;

                    cout << "IV.\t" << intInput << " is ";
                    if (num.isPrime())
                    {
                        cout << "a prime number." << endl;
                    }
                    if (!num.isPrime())
                    {
                        cout << "not a prime number." << endl;
                    }

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
    return 0;
}
int myInt::getInt()
{
    return userNumber;
}
void myInt::setInt(int num)
{
    userNumber = num;
}
bool myInt::isMultiple(int multiplier)
{
    if (userNumber % multiplier == 0)
    {
        return true;
    }
    return false;
}
bool myInt::sumIsEven()
{
    int sumNum = 0;
    int tempNum = userNumber;
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
double myInt::getSquareRoot()
{
    return pow(userNumber, 0.5);
}
bool myInt::isPrime()
{
    int multCount = 0;
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
bool myInt::isPerfect()
{
    int perfectCount = 0;
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
myInt::myInt()
{
    userNumber = 0;
}