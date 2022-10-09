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


};

int main() {
    stack myStack;
    myStack.push(5);
    myStack.push(6);
    myStack.push(7);
    myStack.push(8);
    myStack.print();

    cout << "Count: " << myStack.size() << endl;
    cout << "TEST: " << myStack.peek() << endl;
    cout << "TEST: " << myStack.peek() << endl;
    cout << "1:" << myStack.pop() << endl;
    myStack.print();
    cout << "2:" << myStack.pop() << endl;
    myStack.print();
    cout << "3:" << myStack.pop() << endl;
    myStack.print();
    cout << "Count: " << myStack.size() << endl;
    cout << "Is empty: " << myStack.isEmpty() << endl;
    myStack.print();
    myStack.pop();
    myStack.print();
    cout << "Count: " << myStack.size() << endl;
    cout << "Is empty: " << myStack.isEmpty() << endl;
    myStack.print();
    cout << "Testing Empty(): " << endl;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    cout << "Length: " << myStack.size() << endl;
    myStack.print();
    myStack.empty();
    myStack.print();
    cout << "Length: " << myStack.size() << endl;
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
