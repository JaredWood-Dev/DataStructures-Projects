#include <iostream>

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

    queue myQ;
    myQ.push(1);
    myQ.push(2);
    myQ.push(3);
    myQ.print();
    myQ.insert(4,2);
    myQ.print();
    myQ.remove(2);
    myQ.print();
    cout << "Is empty: " << myQ.isEmpty() << endl;
    myQ.empty();
    cout << "Is empty: " << myQ.isEmpty() << endl;
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
    int num = 0;
    num = head->value;
    head = head->prev;
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
        cout << currNode->value;
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
    int num = 0; //Need to change, queue is first in, first out
    num = head->value;
    head = head->prev;
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