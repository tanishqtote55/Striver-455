#include <iostream>
using namespace std;

// Using Extra Variable
// void swapNumbers(int &a, int &b) {
//     int temp = a;
//     a = b;
//     b = temp;
// }

// Using XOR Operator
void swapNumbers(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;  // (a ^ b) ^ b = a
    a = a ^ b;  // (a ^ b) ^ a = b
}



int main() {
    int x = 5, y = 10;
    cout << "Before Swap: x = " << x << ", y = " << y << endl;

    swapNumbers(x, y);

    cout << "After Swap: x = " << x << ", y = " << y << endl;
    return 0;
}
