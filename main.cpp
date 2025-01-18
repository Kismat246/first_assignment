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
    int nodes, maxNodes;
    Node *head, *tail;

    LinkedList(int maxNodes)
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->maxNodes = maxNodes;
        this->nodes = 0;
    }

    int size()
    {
        return this->nodes;
    }

    int capacity()
    {
        return this->maxNodes;
    }

    bool empty()
    {
        return this->nodes == 0;
    }

    bool full()
    {
        return this->nodes >= maxNodes;
    }

    void insertHead(Node *newNode)
    {
        if (!full())
        {
            if (size() == 0)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }
            nodes++;
        }
        else
        {
            cout << "Insert called when linked list full\n";
        }
    }

    void insertTail(Node *newNode)
    {
        if (!full())
        {
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
        else
        {
            cout << "Insert called when linked list full\n";
        }
    }

    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Stack
{
};

void getInput()
{

    bool stop = false;
    string input;
    string shouldContinue;

    while (!stop)
    {
        LinkedList list(10);

        cout << "Enter a number of brackets: ";
        cin >> input;
        // cout << "Your input is " << input << endl;

        for (char c : input)
        {
            Node *newNode = new Node(c);
            list.insertTail(newNode);
        }

        cout << "Linked list content: ";
        list.display();

        cout << "Do  you want to continue? Yes/No: ";
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
