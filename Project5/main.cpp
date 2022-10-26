#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

void reverseDisplay(int inputArray[], int index);

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