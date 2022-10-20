#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
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
        //Generate Array
    }

    cout << endl;
    cout << "Jared Wood - Programmer \n October 2022" << endl;

}