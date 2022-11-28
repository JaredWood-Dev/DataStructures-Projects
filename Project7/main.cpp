//Author: Jared Wood
//Serial Number: 51
//Due Date  11/28/22
//Programming Assignment Number 7
//Fall 2022 - CS 3358 - 001
//Instructor: Husain Gholoom
//Description:
//To display understanding and implementation of Hash structures

#include <string>
#include <iostream>
#include <fstream>

using namespace std;
class myHash
{
    private:
        int pos; //Stores the current location in the array
        string array[27]; //The array for storing elements of the Hash
        //function
    public:
    myHash();
    //Default constructor, initializes data
    void insert(string input, bool display);
    //Inserts data into the Hash structure
    int search(string key);
    //Searches the Hash for a desired key
    int Hash(string key);
    //Returns the appropriate location for the given key
    int reHash(int key);
    //Returns the next appropriate location for the given key
    void Delete(string key);
    //Deletes an element from the Hash
    void display();
    //Displays the table
};
//---------------------------------------------------------------------------
//This class implements a Hash data structure, allowing for
//quick and efficient storing and searching of data
//
//public items:
//pos - stores the current location in the array
//array - the array of elements
//private items:
//myHash - default constructor, initializes array with '-'
//insert() - inserts an element into the appropriate location
//search() - searches the array, using linear probing, for the desired key
//Hash() - determines the location of a given key
//reHash() - determines the next location of a given key
//Delete() - deletes the given key from the array
//display() - displays the entre array in the desired grid
//----------------------------------------------------------------------------


int main()
{
    cout << "Hashing Program" << endl;
    cout << "--------------------------------" << endl;
    cout << "A. Creates an array of size 27. Assigning - to each location in "
            "the array indicating that the array is empty." << endl;

    //Create the list, constructor populates with "-"
    myHash projectList;

    cout << "B. Populates 26 elements of the array with words." << endl;

    //File operaions
    ifstream myFile; //Stores the open file
    myFile.open("Word.txt");
    string text; //Used for storing the text of the file
    if (myFile.is_open())
    {
        while (getline(myFile,text))
        {
            projectList.insert(text, false);
        }
        myFile.close();
    }

    cout << "C. If a collision occurs, linear probing will find the next"
            "available location / position" << endl;
    cout << "D. The generated array will be displayed in 7 lines. Each line"
            "contains 4 words seperated by tab spaces" << endl << endl;

    cout << "The Generated Array." << endl;
    projectList.display();
    cout << endl << endl;

    //Searching for elements
    projectList.search("Zulu");
    cout << endl;
    projectList.search("Hulu");
    cout << endl;

    //Inserting elements
    projectList.insert("Mayday", true);
    cout << endl;

    projectList.insert("Bonanza", true);
    cout << endl;

    //Display the table again
    cout << "The Table after the words were inserted: " << endl;
    projectList.display();
    cout << endl << endl;


    //Delete elements
    projectList.Delete("Zulu");
    cout << endl;

    projectList.Delete("Delta");
    cout << endl;

    projectList.Delete("Bonanza");
    cout << endl;

    //Display the table a final time
    cout << "The table after 2 word was deleted:" << endl;
    projectList.display();
    cout << endl << endl;

    cout << "This hashing program was implemented by" << endl;
    cout << "Jared Wood" << endl;
    cout << "11-28-2022" << endl;

    return 0;
}

myHash::myHash() {
    for (int i = 0; i < 27; ++i) {
        array[i] = "-";
    }
    pos = 0;
}
//--------------------------------------
//Default constructor for the Hash
//Initializes the array with dashes (-)
//--------------------------------------

void myHash::insert(string input, bool display) {
    int count = 0; //Stores how many checks have occurred
                //if they exceed the limit of the array, it is full
    pos = Hash(input);
    if (pos >= 27)
    {
        pos = 0;
    }
    if (display) {
        cout << "Inserting a New word (" << input << ") in the table." << endl;
    }
    while (array[pos] != "-")
    {
        pos = reHash(pos);
        if (pos > 27)
        {
            pos = 0;
        }
        count++;
        if (count >= 27)
        {
            if (display) {
                cout << "The word (" << input << ") was not inserted. "
                                                 "Table is full." << endl;
            }
            return;
        }
    }
    if (array[pos] == "-")
    {
        array[pos] = input;
    }
    if (display) {
        cout << "The word (" << input << ") is inserted in location "
             << pos << endl;
    }

}
//--------------------------------------------------------------
//Stores the given input into the next appropriate location in
//the array
//
//param-1: input - data to be stored
//param-2: display - tells the function to display storing information
//on true and nothing on false
//--------------------------------------------------------------

int myHash::Hash(string key)
{
    return key.length();
}
//--------------------------------------------------------------
//Returns the appropriate location for information
//
//param-1: key - the data to be stored
//--------------------------------------------------------------

int myHash::reHash(int key)
{
    return key + 1;
}
//--------------------------------------------------------------
//Returns the next appropriate location for information
//
//param-1: key - the data to be stored
//--------------------------------------------------------------

int myHash::search(string key)
{
    int i; //Variable used for indexing purposes
    int count = 0; //Stores the amount of indexes searched;
                //terminates if all indexes have been searched.
    bool isFound = false; //Stores weather the key has been found or not

    //Find the first position where the key should be
    i = Hash(key);

    cout << "Searching for a word (" << key << ") in the table." << endl;
    while (!isFound)
    {
        //If all locations have been checked, key is not in the array
        if (count > 27)
        {
            cout << "The word (" << key << ") was not found in the table"
            << endl;
            cout << endl << "The number of linear probes when each number is"
                            "hashed and collision occurred when searching for"
                            "the word (" << key << ") in the array is " <<
                            count-1 << endl;
            return -1;
        }
        //If the current location has the key
        if (array[i] == key)
        {
            cout << "The word (" << key << ") has been found in location "
            << i << endl;
            cout << endl << "The number of linear probes when each number is"
                            "hashed and collision occurred when searching for"
                            "the word (" << key << ") in the array is " <<
                 count-1 << endl;
            isFound = true;
            return i;
        }

        //Linear probe the next location
        i = reHash(i);
        count++;

        //If greater than the bounds, wrap to zero
        if (i > 27)
        {
            i = 0;
        }

    }
}
//-------------------------------------------------------------
//Searches for the key by linear probing the array
//
//param-1: key - the string to be searched for
//return: the index where the key is located, -1 otherwise
//-------------------------------------------------------------

void myHash::Delete(string key)
{
    int loc; //Stores the location of the key to be deleted
    int i; //Variable used for indexing purposes
    int count = 0; //Stores the amount of indexes searched;
    //terminates if all indexes have been searched.
    bool isFound = false; //Stores weather the key has been found or not

    //Find the first position where the key should be
    i = Hash(key);

    cout << "Deleting the word (" << key << ") from the table." << endl;
    while (!isFound)
    {
        //If all locations have been checked, key is not in the array
        if (count > 27)
        {
            cout << "The word (" << key << ") is not found"
                 << endl;
            cout << endl << "The number of linear probes when each number is"
                            "hashed and collision occurred when deleting"
                            "the word (" << key << ") in the array is " <<
                 count-1 << endl;
            return;
        }
        //If the current location has the key
        if (array[i] == key)
        {
            isFound = true;
            loc = i;
        }

        //Linear probe the next location
        i = reHash(i);
        count++;

        //If greater than the bounds, wrap to zero
        if (i > 27)
        {
            i = 0;
        }

    }

    //If the key exists, clear the location
    if (loc != -1)
    {
        array[loc] = "-";
        cout << "The word (" << key << ") is deleted." << endl;
        cout << endl << "The number of linear probes when each number is"
                        "hashed and collision occurred when deleting "
                        "the word (" << key << ") in the array is " <<
             count-1 << endl;
    }
    else
    {
        //cout << "No key found!" << endl;
    }
}
//----------------------------------------------------------
//Deletes the key from the array
//
//param-1: key - string to be deleted
//----------------------------------------------------------

void myHash::display()
{
    //cout << "The Generated Array: " << endl;
    for (int i = 0; i < 27; ++i) {
        cout << array[i] << "\t";
        if ((i+1) % 4 == 0 && i != 0)
        {
            cout << endl;
        }
    }
}
//-------------------------------------------------------------
//Displays the entirety of the array
//-------------------------------------------------------------