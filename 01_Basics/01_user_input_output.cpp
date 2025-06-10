/*
    Input Output
    Complete the function printNumber which takes an integer input from the user and prints it on the screen.

    Use:-
        for C++ : cout << variable_name;
        for Java : System.out.print();
        for Python : print()
        for Javascript : console.log()

    Examples:
    Input(user gives value): 7

    Output: 7

    Input(user gives value): -5

    Output: -5
*/

#include <iostream>
using namespace std;

class Solution {
public:
    void printNumber() {
        int num;
        cin >> num;    
        cout << num;         
    }
};

int main() {
    Solution sol;
    sol.printNumber();
    return 0;
}
