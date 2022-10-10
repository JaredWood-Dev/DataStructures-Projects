#include <iostream>
#include <time.h>

//TODO Adhere to style guideline and test program in codeblocks
using namespace std;
class stack
{
    public:
        stack();
        ~stack();

        void push(int input);
        int pop();
        int peek();
        int size();
        bool isEmpty();
        void empty();
        void print();

    private:
        struct stackNode
        {
            int value;
            stackNode *next;
            stackNode *prev;
        };
        stackNode *head;
        stackNode *originNode;
        int index;
};

class queue
{
    public:
        queue();
        ~queue();

        void push(int input);
        void insert(int input, int inputIndex);
        int pop();
        void remove(int inputIndex);
        bool isEmpty();
        void empty();
        void print();
        int max();
        int min();

    private:
        struct queueNode
        {
            int value;
            queueNode *next;
            queueNode *prev;
        };
        queueNode *originNode;
        queueNode *head;
        int index;
};

int main() {

    srand(time(0));
    while (true)
    {
        //Part A: Stack of 7 random numbers
        stack myStack;
        for (int i = 0; i < 7; ++i) {
            myStack.push(rand() % 6 + 60);
        }
        cout << "A. Stack of 7 random integers: " << endl;
        myStack.print();

        //Part B: Queue of 7 random numbers
        queue myQueue;
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

        char userInput = ' ';
        cout << "Enter 'X' to end the program. Enter anything else to continue "
                "the program" << endl;
        cin >> userInput;
        if (userInput == 'X')
        {
            break;
        }
    }
    cout << "Thank you for using this Linked List-Based Stack and Queue "
            "program."<< endl;
    cout << "This program was implemented by Jared Wood on 10-9-22" << endl;
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

stack::~stack()
{

}

void stack::push(int input)
{
    stackNode *newNode = new stackNode;
    newNode->value = input;
    if (index == 0)
    {
        originNode = newNode;
        originNode->prev = nullptr;
        originNode->next = nullptr;
        head = newNode;
        head->next = nullptr;
        head->prev = nullptr;
    }
    else
    {
        newNode->prev = head;
        head->next = newNode;
        head = head->next;
    }
    index++;
}

int stack::pop()
{
    if (index == 0)
    {
        cout << "There are no elements in the stack." << endl;
        return -1;
    }
    int num = 0;
    num = head->value;
    head = head->prev;
    free(head->next);
    index--;
    return num;
}

int stack::peek()
{
    return head->value;
}
int stack::size()
{
    return index;
}
bool stack::isEmpty()
{
    if (originNode == nullptr || head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void stack::empty()
{
    stackNode *currNode = originNode;
    while(currNode != nullptr)
    {
        currNode = currNode->next;
        free(currNode->prev);
        if (currNode == head)
        {
            break;
        }

    }
    index = 0;
}
void stack::print()
{
    stackNode *currNode = originNode;
    int i = 0;
    while( i < index)
    {
        cout << currNode->value << " ";
        currNode = currNode->next;
        i++;
    }
    if (index == 0)
    {
        cout << "There are no elements in the stack." << endl;
        return;
    }
    cout << endl;
}
queue::queue()
{
    index = 0;
    originNode = nullptr;
}
queue::~queue()
{

}
void queue::push(int input)
{
    queueNode *newNode = new queueNode;
    newNode->value = input;
    if (originNode == nullptr)
    {
        originNode = newNode;
        originNode->next = nullptr;
        originNode->prev = nullptr;
        head = newNode;
        head->next = nullptr;
        head->prev = nullptr;
    }
    else
    {
        newNode->prev = head;
        head->next = newNode;
        head = newNode;
    }
    index++;
}

void queue::insert(int input, int inputIndex)
{
    if (inputIndex > index)
    {
        cout << "Error: Out of bounds." << endl;
        return;
    }

    queueNode *indexPointer = new queueNode;
    int loc = 0;
    indexPointer = originNode;
    while(indexPointer != nullptr)
    {
        if(loc == inputIndex)
        {
            queueNode *newNode = new queueNode;
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
            break;
        }
        indexPointer = indexPointer->next;
    }

}
int queue::pop()
{
    if (index == 0)
    {
        cout << "There are no elements in the queue." << endl;
        return -1;
    }
    int num = 0;
    num = originNode->value;
    originNode = originNode->next;
    free(originNode->prev);
    index--;
    return num;
}

void queue::remove(int inputIndex)
{
    if (index == 0)
    {
        cout << "There are no elements in the queue." << endl;
        return;
    }

    queueNode *indexNode = originNode;
    int i = 0;
    while ( i < index)
    {
        if (inputIndex == i)
        {
            indexNode->prev->next = indexNode->next;
            indexNode->next->prev = indexNode->prev;
            index--;
            return;
        }
        i++;
        indexNode = indexNode->next;
    }
}

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

void queue::empty()
{
    queueNode *currNode = originNode;
    while(currNode != nullptr)
    {
        currNode = currNode->next;
        free(currNode->prev);
        if (currNode == head)
        {
            break;
        }

    }
    index = 0;
}

void queue::print()
{
    queueNode *currNode = originNode;
    int i = 0;
    while( i < index)
    {
        cout << currNode->value << " ";
        currNode = currNode->next;
        i++;
    }
    if (index == 0)
    {
        cout << "There are no elements in the queue." << endl;
        return;
    }
    cout << endl;
}

int queue::max()
{
    int max = 0;
    int i = 0;
    queueNode *indexNode = originNode;
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

int queue::min()
{
    int min = 0;
    int i = 0;
    queueNode *indexNode = originNode;
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