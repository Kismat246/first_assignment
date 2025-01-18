#include <iostream>
#include <cctype>
# include <algorithm>
using namespace std;

void getInput()
{

    bool stop = false;
    string input;
    string shouldContinue;

    while (stop == false)
    {
        cout << "Enter a number of brackets: ";
        cin >> input;
        cout << "Your input is " << input << endl;
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
        }else {
            cout << "Invalid input. Assuming you want to stop" << endl;
        }
    }
}


int main()
{
    getInput();
    return 0;
}
