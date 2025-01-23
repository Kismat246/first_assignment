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
        // cout << "node value: " << nodes << endl;
        return this->nodes == 0;
    }

    // for stack
    void insertAtHead(char singleBracket)
    {
        Node *newNode = new Node(singleBracket);
        if (isEmpty())
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

    // adds a new node in the last of the linked list
    void insertTail(char singleBracket)
    {

        Node *newNode = new Node(singleBracket);
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

    // adds a new node at the last of the linked list, for queue
    void insertAtLast(char singleBracket)
    {
        // cout << "this item going to be inserted at second list: " << singleBracket << endl;
        Node *newNode = new Node(singleBracket);
        if (size() == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        nodes++;
    }

    // deletes the item that was added at first, for queue
    char deleteAtHead()
    {
        if (!isEmpty()) // if we have more or equal to one item in the list we delete
        {
            Node *temp = head;
            char value = temp->value;

            if (size() > 1)
            {
                temp->next->prev = nullptr;
                head = temp->next;
            }
            delete temp;
            nodes--;
            return value;
        }
        else
        { // or else dont delete just return
            return '\0';
        }
    }

    // removes the most recent node added in the list, which is the last node
    void deleteTail()
    {
        Node *temp = tail;
        // if (temp != nullptr)
        // {
        //     cout << "tail: " << temp << " temp value: " << temp->value << endl;
        // }

        if (!isEmpty())
        {
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
    void push(char singleBracket)
    {
        // list.insertTail(singleBracket);
        list.insertAtHead(singleBracket);
    }

    // deletes item from the stack
    void pop()
    {
        list.deleteAtHead(); // deletes the first item from the stack which is recently added one
    }

    // checks if the stack is empty or not
    bool isEmpty()
    {
        return list.isEmpty();
    }

    void display()
    {
        list.display();
    }

    // deletes every item from the stack
    void clearStack()
    {
        while (!list.isEmpty()) // ensures that every item from the stack will be deleted until it is empty
        {
            pop();
        }
    }

    int size()
    {
        return list.size();
    }
};

class StackParenthesesChecker
{
private:
    Stack stack;

public:
    bool balancedParenthesesStack(string input)
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
                    // cout << "stack is empty" << endl;
                    return false;
                }
                stack.pop();
            }
            // stack.push(c);
        }
        isListEmpty = stack.isEmpty();
        stack.clearStack();
        return isListEmpty;
    }

    // deletes the single item from the stack
    void pop()
    {
        stack.pop();
    }

    void display()
    {
        stack.display();
    }
};

class Queue
{

private:
    LinkedList list1, list2;

public:
    // adds the item in the queue
    void enque(char singleBracket)
    {
        list1.insertAtLast(singleBracket);
    }

    // removes the first added item from the queue
    char dequeue()
    {
        while (!list1.isEmpty()) // checking whether we have items in our first queue or not
        {
            list2.insertAtLast(list1.deleteAtHead());
        }

        return list2.deleteAtHead();
    }

    // checks whether the queues are empty or not
    bool isQueueEmpty()
    {
        // cout << "lis1.nodes: " << list1.nodes << "\nlist2.nodes: " << list2.nodes << endl;
        return list1.isEmpty() && list2.isEmpty();
    }

    // delete every item from the queue
    void clearQueue()
    {
        while (!list1.isEmpty() || !list2.isEmpty())
        { // will delete every item until the both queue list is cleared
            list1.deleteAtHead();
            list2.deleteAtHead();
        }
    }

    int sizeOfList1()
    {
        return list1.size();
    }

    int sizeOfList2()
    {
        return list2.size();
    }

    void displayList()
    {
        list1.display();
    }
};

class QueueParenthesesChecker
{
private:
    Queue queue;

public:
    /*
        this method adds the input '(' in a first queue and then if the input is ')', it takes out the
        first element from the first queue and puts it in the second queue and lastly deletes the first element from
        the second queue and returns true if there is no element in both queues otherwise returns false
        if there is still element left in either first or second queues
    */
    bool balancedParenthesesQueue(string input)
    {
        bool isListEmpty = false;
        for (char singleBracket : input)
        {
            if (singleBracket == '(') // adds the bracket in the first queue
            {
                queue.enque(singleBracket);
            }
            else if (singleBracket == ')') // deletes the first bracket from the first queue
            {
                if (queue.isQueueEmpty())
                {
                    return false;
                }
                queue.dequeue();
            }
        }
        isListEmpty = queue.isQueueEmpty();
        queue.clearQueue();
        return isListEmpty;
    }

    void display()
    {
        queue.displayList();
    }
};

void getInput()
{

    bool stop = false;
    string input;
    string shouldContinue;
    StackParenthesesChecker stackParenthesesChecker;
    QueueParenthesesChecker queueParenthesesChecker;

    while (!stop)
    {
        bool validInput = false;
        while (!validInput)
        {
            cout << "\nThis program checks whether the input parentheses are balanced or not.\n";
            cout << "Enter a number of brackets: ";
            cin >> input;
            cout << "\nYour input is " << input << endl;

            validInput = true;

            for (char i : input){
                if (i != '(' && i != ')'){
                    validInput = false;
                    break;
                }
            }

            if (!validInput){
                cout << "\nInvalid input! Please enter only '(' or ')' characters.\n";
            }
        }

        bool isBalancedStack = stackParenthesesChecker.balancedParenthesesStack(input);
        bool isBalancedQueue = queueParenthesesChecker.balancedParenthesesQueue(input);
        // queueParenthesesChecker.display();

        // cout <<"\n isBalancedStack: " << isBalancedStack << endl;
        // cout << "\n isBalancedQueue: " << isBalancedQueue << endl;

        if (isBalancedStack == true && isBalancedQueue == true)
        {
            cout << "\nThe input has balanced parentheses using Stack and Queue" << endl;
        }
        else
        {
            cout << "\nThe input does not have balanced parentheses using Stack and Queue" << endl;
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

    // StackParenthesesChecker stackParenthesesChecker;
    // QueueParenthesesChecker queueParenthesesChecker;

    // string input = "()(()))()()";

    // bool isBalancedStack = stackParenthesesChecker.balancedParentheses(input);
    // bool isBalancedQueue = queueParenthesesChecker.balancedQueueParenthesesChecker(input);

    // if (isBalancedStack == true)
    // {
    //     cout << "Parentheses are balanced using Stack " << input << endl;
    // }
    // else
    // {
    //     cout << "Parentheses are not balanced using Stack " << input << endl;
    // }
    // if (isBalancedQueue)
    // {
    //     cout << "parentheses are balanced using Queue " << input << endl;
    // }
    // else
    // {
    //     cout << "parentheses are not balanced using queue " << input << endl;
    // }

    return 0;
}
