//Author: Jared Wood
//Serial Number: 51
//Programming Assignment Number 4
//Fall 2022 - CS 3358 - 001
//Due Date: 10-10-22
//Instructor Husian Gholoom
//Description:
//This program is designed to demonstrate understanding in both implementation
//of pointer-based linked lists, and stack and queue data types.

#include <iostream>
#include <time.h>

//TODO Adhere to style guideline and test program in codeblocks
using namespace std;
class stack
{
    public:
        stack();
        //Default constructor
        ~stack();
        //Default destructor

        void push(int input);
        //Appends a node to the end
        int pop();
        //Removes a node from the end
        int peek();
        //Gets the value of the last node
        int size();
        //Gets the size of the stack
        bool isEmpty();
        //Returns if the stack is empty
        void empty();
        //Empties the stack
        void print();
        //Prints all the elements of the stack

    private:
        struct stackNode //This creates the node element for the stack
        {                   //Used to handle creation of the stack
            int value; //Stores data for the node
            stackNode *next; //Pointer to the next node
            stackNode *prev; //Pointer to the previous node
        };
        stackNode *head; //Pointer that represents the current end of the stack
        stackNode *originNode; //Pointer that represents the beginning of the
                                //stack
        int index; //Stores the current length of the stack
};
//------------------------------------------------------------------------------
//Creates a stack ADT with functions to manipulate the stack
//
//Public: stack(), ~stack(), push(), pop(), peek(), size, isEmpty(), empty
//print()
//Private: stackNode, head, originNode, index
//------------------------------------------------------------------------------

class queue
{
    public:
        queue();
        //Default Constructor
        ~queue();
        //Default Destructor

        void push(int input);
        //Appends a node to the end of the queue
        void insert(int input, int inputIndex);
        //Inserts a node to a desired a position in the queue
        int pop();
        //Removes and returns the first node in the queue
        void remove(int inputIndex);
        //Removes the desired node from the queue
        bool isEmpty();
        //Returns weather the queue is empty
        void empty();
        //Empties the queue
        void print();
        //Prints all the elements in the queue
        int max();
        //Finds the higher value element in the queue
        int min();
        //Finds the lowest value element in the queue
    private:
        struct queueNode //This creates a node for the queue
        {
            int value; //Stores data for the node
            queueNode *next; //Pointer to the next node
            queueNode *prev; //Pointer to the previous node
        };
        queueNode *originNode; //Pointer that represents the beginning of the
                                //queue
        queueNode *head; //Pointer tht represents the end of the queue
        int index; //Stores the length of the queue
};
//------------------------------------------------------------------------------
//Creates a queue ADT with functions to manipulate the queue
//
//Public: queue(), ~queue(), push(), pop(), peek(), size, isEmpty(), empty
//print(), insert(), remove(), min(), max()
//Private: queueNode, head, originNode, index
//------------------------------------------------------------------------------

int main() {

    srand(time(0));

    cout << "Welcome to this linked list-based stack and queue program."
    << endl;
    cout << "The purpose of this program is to:" << endl;
    cout << "Create a stack and queue, and fill them with a range of random"
            "numbers." << endl;
    cout << "Test each structure type by adding and removing elements." << endl;
    cout << "Finally delete all the elements in each and accurately test"
            "error handling." << endl;
    while (true)
    {
        //Part A: Stack of 7 random numbers
        stack myStack; //The stack used by the program
        for (int i = 0; i < 7; ++i) {
            myStack.push(rand() % 6 + 60);
        }
        cout << "A. Stack of 7 random integers: " << endl;
        myStack.print();

        //Part B: Queue of 7 random numbers
        queue myQueue; //The queue used by the program
        for (int i = 0; i < 7; ++i) {
            myQueue.push(rand() % 6 + 105);
        }
        cout << "B. Queue of 7 random integers: " << endl;
        myQueue.print();

        //Part C: Insert -20 into the stack
        cout << "C. Insert the element -20 in the stack" << endl;
        myStack.push(-20);
        myStack.print();

        //Part D: Remove the top two elements from the stack
        cout << "D. Remove the top two elements from the stack" << endl;
        myStack.pop();
        myStack.pop();
        myStack.print();

        //Part E: Insert -500 into the queue
        cout << "E. Insert the element -500 into the queue" << endl;
        myQueue.push(-500);
        myQueue.print();


        //Part F: Insert an element -200 into the 3rd location of the queue
        cout << "F. Insert an element -200 into the 3rd location of the queue"
            << endl;
        myQueue.insert(-200, 2);
        myQueue.print();

        //Part G: Remove the first element from the queue
        cout << "G. Remove the first element from the queue" << endl;
        myQueue.pop();
        myQueue.print();

        //Part H: Remove the fourth element from the queue
        cout << "H. Remove the fourth element the queue" << endl;
        myQueue.remove(4);
        myQueue.print();

        //Part I: Find the min and max elements in the queue
        cout << "I. Find the minimum and maximum elements in the queue" << endl;
        cout << "Max: " << myQueue.max() << " Min: " << myQueue.min() << endl;
        myQueue.print();

        //Part J: Delete the entire stack
        cout << "J. Deleting the Stack" << endl;
        myStack.empty();

        //Park K: Try to delete first element
        cout << "K. Attempting to delete first element of the stack" << endl;
        myStack.pop();

        //Park L: Delete the entire queue
        cout << "L. Deleting the Queue" << endl;
        myQueue.empty();

        //Part M: Try to delete the first element
        cout << "M. Attempting to delete first element of the queue" << endl;
        myQueue.pop();

        char userInput = ' '; //Stores the user's input. If 'X' the program
                                //terminates
        cout << "Enter 'X' to end the program. Enter anything else to continue "
                "the program: " << endl;
        cin >> userInput;
        if (userInput == 'X')
        {
            break;
        }
    }
    cout << "Thank you for using this Linked List-Based Stack and Queue "
            "program."<< endl;
    cout << "This program was implemented by Jared Wood on 10-10-22" << endl;
    return 0;
}

stack::stack()
{
    /*originNode = new stackNode;
    originNode->value = 0;
    originNode->prev = nullptr;
    originNode->next = nullptr;
    */index = 0;
}
//-----------------------------------------------------------------------------
//Default constructor for the stack
//-----------------------------------------------------------------------------

stack::~stack()
{
    //empty();
}
//-----------------------------------------------------------------------------
//Default destructor for the stack
//-----------------------------------------------------------------------------

void stack::push(int input)
{
    stackNode *newNode = new stackNode; //Creates a new node for the stack

    //Assign value to the node
    newNode->value = input;

    //If the stack is empty, make this the new origin node
    if (index == 0)
    {
        originNode = newNode;
        originNode->prev = nullptr;
        originNode->next = nullptr;
        head = newNode;
        head->next = nullptr;
        head->prev = nullptr;
    }

    //otherwise, just append the node to the end
    else
    {
        newNode->prev = head;
        head->next = newNode;
        head = head->next;
    }

    //Increase stack length
    index++;
}
//-----------------------------------------------------------------------------
//Appends a new node to the end of the stack
//param-1: int input - what value is to be assigned to the node
//-----------------------------------------------------------------------------

int stack::pop()
{
    //Checks if there are no elements and returns an error message if there are
        //none
    if (index == 0)
    {
        cout << "There are no elements in the stack." << endl;
        return -1;
    }

    //Get the value of the end node and free the end node from memory
    int num = 0; //Gets the value of the node
    num = head->value;
    head = head->prev;
    free(head->next);
    index--;
    return num;
}
//-----------------------------------------------------------------------------
//Deletes and returns the value of the last node in the stack
//
//return: value of the final node
//-----------------------------------------------------------------------------

int stack::peek()
{
    //Return what the last node value has
    return head->value;
}
//-----------------------------------------------------------------------------
//Gets the value of the final node
//
//return: value of the final node
//-----------------------------------------------------------------------------

int stack::size()
{
    //Return the size
    return index;
}
//-----------------------------------------------------------------------------
//Gets the size of the stack
//
//return: the size of the stack
//-----------------------------------------------------------------------------

bool stack::isEmpty()
{
    //If the origin or the head doesn't exist then the stack is empty
    if (originNode == nullptr || head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//-----------------------------------------------------------------------------
//Checks if the stack is empty
//
//return: a boolean; true if the stack is empty, false is the stack has nodes
//-----------------------------------------------------------------------------

void stack::empty()
{
    stackNode *currNode = originNode; //Creates a node for iterating through the
                                        // stack
    //Loops through the stack, stops when all nodes have been freed
    while(currNode != nullptr)
    {
        currNode = currNode->next;
        free(currNode->prev);
        if (currNode == head)
        {
            break;
        }

    }
    //Length is now zero as there are no nodes
    index = 0;
}
//-----------------------------------------------------------------------------
//Empties the stack
//-----------------------------------------------------------------------------

void stack::print()
{
    stackNode *currNode = originNode; //Node for iteration
    int i = 0; //Iteration variable

    //Iterates through the stack, prints the value of each node
    while( i < index)
    {
        cout << currNode->value << " ";
        currNode = currNode->next;
        i++;
    }
    //Checks if there are elements in the stack
    if (index == 0)
    {
        cout << "There are no elements in the stack." << endl;
        return;
    }
    cout << endl;
}
//-----------------------------------------------------------------------------
//Prints all the elements in the stack
//-----------------------------------------------------------------------------

queue::queue()
{
    index = 0;
    originNode = nullptr;
}
//-----------------------------------------------------------------------------
//Default constructor for the queue
//-----------------------------------------------------------------------------

queue::~queue()
{
    //empty();
}
//-----------------------------------------------------------------------------
//Default destructor for the queue
//-----------------------------------------------------------------------------

void queue::push(int input)
{
    queueNode *newNode = new queueNode; //Creates a new node for the queue

    //Assign vale to the node
    newNode->value = input;

    //If the queue is empty assign the origin node
    if (originNode == nullptr)
    {
        originNode = newNode;
        originNode->next = nullptr;
        originNode->prev = nullptr;
        head = newNode;
        head->next = nullptr;
        head->prev = nullptr;
    }

    //Otherwise, append the node to the end
    else
    {
        newNode->prev = head;
        head->next = newNode;
        head = newNode;
    }

    //Increase the size of the queue
    index++;
}
//-----------------------------------------------------------------------------
//Appends a new node to the end of the queue
//
//param-1: int input - data to be assigned to the new node
//-----------------------------------------------------------------------------

void queue::insert(int input, int inputIndex)
{
    //Ensures that the desired index is in the bounds of the queue
    if (inputIndex > index)
    {
        cout << "Error: Out of bounds." << endl;
        return;
    }

    queueNode *indexPointer = new queueNode; //Creates a new node for indexing
    int loc = 0; //Variable for indexing purposes

    //Start at the origin
    indexPointer = originNode;

    while(indexPointer != nullptr)
    {
        if(loc == inputIndex)
        {
            //Inserting the node at te desired location
            queueNode *newNode = new queueNode; //Creates a new node to be
                                                    //inserted
            newNode->value = input;
            newNode->prev = indexPointer->prev;
            newNode->next = indexPointer;
            indexPointer->prev->next = newNode;
            indexPointer->prev = newNode;
            index++;
        }
        loc++;
        if (loc == index)
        {
            //No need to continue looping, exit
            break;
        }
        indexPointer = indexPointer->next;
    }

}
//-----------------------------------------------------------------------------
//Inserts a new node ath the desired location
//
//param-1: int input - the data to be stored in the new node
//param-2: int inputIndex - location to insert the new node
//-----------------------------------------------------------------------------

int queue::pop()
{
    //Checks to ensure that there are elements in the queue to begin with
    if (index == 0)
    {
        cout << "There are no elements in the queue." << endl;
        return -1;
    }
    int num = 0; //Stores the value of the node

    //Move the origin node, free the original first node
    num = originNode->value;
    originNode = originNode->next;
    free(originNode->prev);

    //Shorten the queue
    index--;
    return num;
}
//-----------------------------------------------------------------------------
//Deletes and returns the value of the first element
//
//return: the value of the first element
//-----------------------------------------------------------------------------

void queue::remove(int inputIndex)
{
    //Ensures that there are elements to remove
    if (index == 0)
    {
        cout << "There are no elements in the queue." << endl;
        return;
    }

    queueNode *indexNode = originNode; //Creates a node for indexing
    int i = 0; //Variable for indexing purposes
    while ( i < index)
    {
        if (inputIndex == i)
        {
            //Removes the desired node
            indexNode->prev->next = indexNode->next;
            indexNode->next->prev = indexNode->prev;
            index--;
            return;
        }
        i++;
        indexNode = indexNode->next;
    }
}
//-----------------------------------------------------------------------------
//Removes the desired node
//
//param-1: int inputIndex - location of the node to be removed
//-----------------------------------------------------------------------------

bool queue::isEmpty()
{
    if(index == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//-----------------------------------------------------------------------------
//Checks if the queue is empty
//
//return: boolean; true if the queue is empty, false otherwise
//-----------------------------------------------------------------------------

void queue::empty()
{
    queueNode *currNode = originNode; //Node for indexing
    while(currNode != nullptr)
    {
        currNode = currNode->next;
        if (currNode->prev != nullptr)
        {
            //Free each node
            free(currNode->prev);
        }

        if (currNode == head)
        {
            //Once we get to the end, break out of the loop
            break;
        }

    }

    //Size is now zero
    index = 0;
}
//-----------------------------------------------------------------------------
//Empties the queue
//-----------------------------------------------------------------------------

void queue::print()
{
    queueNode *currNode = originNode; //Node for indexing purposes
    int i = 0; //Variable for indexing purposes
    while( i < index)
    {
        //Print the value of each node
        cout << currNode->value << " ";
        currNode = currNode->next;
        i++;
    }

    //Ensure there are elements to print
    if (index == 0)
    {
        cout << "There are no elements in the queue." << endl;
        return;
    }
    cout << endl;
}
//-----------------------------------------------------------------------------
//Prints all the elements in the queue
//-----------------------------------------------------------------------------

int queue::max()
{
    int max = 0; //Variable for storing the maximum value
    int i = 0; //Variable for indexing purposes
    queueNode *indexNode = originNode; //Node for indexing purposes

    //Iterate throughout the queue, linear search for max value.
    while (i < index)
    {
        if (indexNode->value > max)
        {
            max = indexNode->value;
        }
        indexNode = indexNode->next;
        i++;
    }
    return max;
}
//-----------------------------------------------------------------------------
//Finds the largest element in the queue
//
//return: the maximum value in the queue
//-----------------------------------------------------------------------------

int queue::min()
{
    int min = 0; //Variable for storing minimum value
    int i = 0; //Variable for indexing purposes
    queueNode *indexNode = originNode; //Node for indexing purposes

    //Iterate through the queue, finding the minimum node
    while (i < index)
    {
        if (indexNode->value < min)
        {
            min = indexNode->value;
        }
        indexNode = indexNode->next;
        i++;
    }
    return min;
}
//-----------------------------------------------------------------------------
//Finds the smallest element in the queue
//
//return: the minimum value in the queue
//-----------------------------------------------------------------------------