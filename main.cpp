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


    /*
        This method creates a new node and adds the node at the head of the linked list,
        this method is used by stack class to mimic the stack behaviour of adding the new element at top
    */
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


    // adds a new node at the last of the linked list, for queue
    void insertAtLast(char singleBracket)
    {
        // cout << "this item going to be inserted at second list: " << singleBracket << endl;
        Node *newNode = new Node(singleBracket);
        if (size() == 0)  // if we have no items in the linked list
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

    
    /*
        This method helps to delete the first node from the linked list and returns the value of the deleted node
    */
    char deleteAtHead()
    {
        if (!isEmpty()) // if we have more or equal to one item in the list we delete
        {
            Node *temp = head;
            char value = temp->value;

            if (size() > 1)  // if the linked list have more than one item 
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


    //  prints out the list's item
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
    
    /*
        This method adds the item on the first of linked list just like a stack, the first added element is at the last,
        like wise the first added element will be at the last of the linked list.
    */
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

    // prints out the item from the stack list
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

    // provides the number of elements in the stack
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
 /*
    this method if the input is '(', adds at head in stack list and deletes the most recently added '(' if the input is
    ')'. And lastly checks if the stack or linked list has any item left. If the list has item left then the user has
    provided unbalanced parenthese or else the input provided by user has balanced parentheses. 
 */
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

    // prints out every elements from the stack list
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

    /*
        This method adds the item at the last of the linked list, just like in queue the first added item is shown at first
        this method puts the items in a way that the first added is shown first and second added is shown second and vice-versa.
    */
    void enque(char singleBracket)
    {
        list1.insertAtLast(singleBracket);
    }

    /*
        This method deletes the first element from the queue and returns the deleted value and put it to the first
        of second queue, delets the second element from the first queue and returns the value and put it to the second 
        of the second queue. This method mimics the behaviour of Queue. This method follows the Firs In First Out as it
        deletes the first item that was added first.  

    */
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

    // returns the size of the linked list1
    int sizeOfList1()
    {
        return list1.size();
    }

    // returns the size of the linked list2
    int sizeOfList2()
    {
        return list2.size();
    }

    // prints out the element inside the list1
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
        queue.clearQueue(); // clearing the queue after checking whether the input has balanced parentheses or not
        return isListEmpty;
    }

    // this method displays the items from the queue
    void display()
    {
        queue.displayList();
    }
};

/*
    This method checks if the input provided by the user is valid or not, if it is valid than it will call another method to
    check if the parentheses are balanced or not. If it is invalid it will asks the user to provide valid input until the user
    provides it. This method also displays whether the input have balanced paretheses or not. This method will run until user
    terminates the program.
*/

void getInput()
{

    bool stop = false;
    string input;
    string shouldContinue;
    StackParenthesesChecker stackParenthesesChecker;
    QueueParenthesesChecker queueParenthesesChecker;

    // program will run until user wants to terminate
    while (!stop)
    {
        bool validInput = false;
        while (!validInput) // loop to ask user for valid input
        {
            cout << "\nThis program checks whether the input parentheses are balanced or not.\n";
            cout << "Enter a number of brackets: ";
            cin >> input;
            cout << "\nYour input is " << input << endl;

            validInput = true;

            // using for loop to go through user input to check if it contains valid input
            for (char i : input)
            {
                if (i != '(' && i != ')')
                {
                    validInput = false;
                    break;
                }
            }

            // display invalid message it the user input is invalid
            if (!validInput)
            {
                cout << "\nInvalid input! Please enter only '(' or ')' characters.\n";
            }
        }

        bool isBalancedStack = stackParenthesesChecker.balancedParenthesesStack(input);
        bool isBalancedQueue = queueParenthesesChecker.balancedParenthesesQueue(input);

        // if both the stack and queue parentheses checker returns true then
        if (isBalancedStack == true && isBalancedQueue == true)
        {
            cout << "\nThe input has balanced parentheses using Stack and Queue" << endl;
        }
        else // if either one or both stack and queue parentheses checker returns false then
        {
            cout << "\nThe input does not have balanced parentheses using Stack and Queue" << endl;
        }

        // asking user wheter the program should be continue or not
        cout
            << "Do  you want to continue? Yes/No: ";
        cin >> shouldContinue;

        cout << "\n";

        // converting the user input for continuation of program into lower case
        transform(shouldContinue.begin(), shouldContinue.end(), shouldContinue.begin(), ::tolower);

        // if user types yes or y or YES the program will run or else it will stop
        if (shouldContinue == "yes" || shouldContinue == "y")
        {
            stop = false;
        }
        else if (shouldContinue == "no" || shouldContinue == "n")
        {

            stop = true;
        }
        else // if the user types anything other than yes or no program will terminate
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
