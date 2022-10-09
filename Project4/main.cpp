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
        bool isFull();
        bool isEmpty();

        void makeEmpty();
        void print();

    private:
        struct quoteNode
        {
            int value;
            quoteNode *next;
            quoteNode *prev;
        };
        quoteNode *head;
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

    cout << "Count: " << myStack.size() << endl;
    cout << "TEST: " << myStack.peek() << endl;
    cout << "TEST: " << myStack.peek() << endl;
    cout << "1:" << myStack.pop() << endl;
    cout << "2:" << myStack.pop() << endl;
    cout << "3:" << myStack.pop() << endl;
    cout << "Count: " << myStack.size() << endl;
    return 0;
}

stack::stack()
{
    quoteNode *originNode = new quoteNode;
    originNode->value = 0;
    head = originNode->next;
    originNode->prev = NULL;
    index = 0;
}

stack::~stack()
{

}

void stack::push(int input)
{
    quoteNode *newNode = new quoteNode;
    newNode->prev = head;
    head = newNode;
    newNode->value = input;
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