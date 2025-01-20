#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

class Node
{
public:
    char value;
    Node *next;
    Node *prev;

    Node(char value)
    {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList
{
public:
    int nodes;
    Node *head, *tail;

    LinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->nodes = 0;
    }

    // returns the number of nodes present in the linked list
    int size()
    {
        return this->nodes;
    }

    bool empty()
    {
        return this->nodes == 0;
    }

    // adds a new node in the last of the linked list
    void insertTail(char bracket)
    {

        Node *newNode = new Node(bracket);
        if (size() == 0)
        {

            head = newNode;
            tail = newNode;
        }
        else
        {

            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        nodes++;
    }

    // removes the most recent node added in the list, which is the last node
    char deleteTail()
    {
        Node *temp = tail;
        char tempValue = temp->value;
        temp->prev->next = nullptr;
        tail = temp;
        delete temp;
        return tempValue;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Stack
{
private:
    LinkedList list;

public:
    // adds item on the stack
    void push(char bracket)
    {
        list.insertTail(bracket);
    }

    // deletes item from the stack
    void pop()
    {
    }

    // checks if the stack is empty or not
    bool isEmpty()
    {
    }

    // checks if the stack is full or not
    bool isFull()
    {
    }

    void display()
    {
        list.display();
    }
};

class StackParenthesesChecker
{
private:
    Stack stack;

public:
    void push(string input)
    {
        for (char c : input)
        {
            stack.push(c);
        }
    }

    void display()
    {
        stack.display();
    }
};

void getInput()
{

    bool stop = false;
    string input;
    string shouldContinue;
    StackParenthesesChecker stackParenthesesChecker;

    while (!stop)
    {
        LinkedList list;

        cout << "Enter a number of brackets: ";
        cin >> input;
        cout << "Your input is " << input << endl;

        stackParenthesesChecker.push(input);

        stackParenthesesChecker.display();

        cout
            << "Do  you want to continue? Yes/No: ";
        cin >> shouldContinue;

        transform(shouldContinue.begin(), shouldContinue.end(), shouldContinue.begin(), ::tolower);

        // cout << shouldContinue << endl;

        if (shouldContinue == "yes")
        {
            stop = false;
        }
        else if (shouldContinue == "no")
        {
            stop = true;
        }
        else
        {
            cout << "Invalid input. Assuming you want to stop" << endl;
        }
    }
}

int main()
{
    getInput();
    return 0;
}
