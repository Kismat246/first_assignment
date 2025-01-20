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

    // checks if the linked list is empty or not
    bool isEmpty()
    {
        cout << "node value: " << nodes << endl;
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
    void deleteTail()
    {
        Node *temp = tail;
        if (temp != nullptr)
        {
            cout << "tail: " << temp << " temp value: " << temp->value << endl;
        }

        if (!isEmpty())
        {
            cout << "link list is not empty" << endl;
            if (nodes > 1)
            {
                temp->prev->next = nullptr;
                tail = temp->prev;
            }
            delete temp;
            nodes--;
        }
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
        // cout << "List is empty";
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
        list.deleteTail();
    }

    // checks if the stack is empty or not
    bool isEmpty()
    {
        return list.isEmpty();
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
    bool balancedParentheses(string input)
    {
        bool isListEmpty = false;
        for (char c : input)
        {
            if (c == '(')
            {
                stack.push(c);
            }
            else if (c == ')')
            {
                if (stack.isEmpty())
                {
                    return false;
                }
                stack.pop();
            }
            // stack.push(c);
        }
        return stack.isEmpty();
    }

    void pop()
    {
        stack.pop();
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

    while (!stop)
    {

        cout << "\nThis program checks whether the input parentheses are balanced or not.\n";
        cout << "Enter a number of brackets: ";
        cin >> input;
        cout << "Your input is " << input << endl;

        StackParenthesesChecker stackParenthesesChecker;
        bool isBalanced = stackParenthesesChecker.balancedParentheses(input);

        if (isBalanced == true)
        {
            cout << "The input has balanced parentheses using Stack" << endl;
        }
        else
        {
            cout << "The input does not have balanced parentheses using Stack" << endl;
        }

        cout
            << "Do  you want to continue? Yes/No: ";
        cin >> shouldContinue;

        cout << "\n";

        transform(shouldContinue.begin(), shouldContinue.end(), shouldContinue.begin(), ::tolower);

        if (shouldContinue == "yes" || shouldContinue == "y")
        {

            stop = false;
        }
        else if (shouldContinue == "no" || shouldContinue == "n")
        {

            stop = true;
        }
        else
        {
            cout << "Invalid input. Assuming you want to stop" << endl;
            stop = true;
        }
    }
}

int main()
{
    getInput();
    return 0;
}
