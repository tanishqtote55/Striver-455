/*
    Problem Statement: Given a number X,  print its factorial.

    To obtain the factorial of a number, it has to be multiplied by all the whole numbers preceding it. More precisely X! = X*(X-1)*(X-2) … 1.

    Note: X  is always a positive number. 

    Examples:

    Example 1:
    Input: X = 5
    Output: 120
    Explanation: 5! = 5*4*3*2*1

    Example 2:
    Input: X = 3
    Output: 6
    Explanation: 3!=3*2*1
*/

#include <iostream>
using namespace std;

int factorial(int n){
    if(n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main(){
  
    int n = 0;
    cout << "Enter a Number: ";
    cin >> n;
    cout<<factorial(n)<<endl;
    return 0;

}