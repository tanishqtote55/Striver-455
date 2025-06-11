/*
    Reverse an array
    Given an array arr of n elements. The task is to reverse the given array. The reversal of array should be inplace.

    Examples:
    Input: n=5, arr = [1,2,3,4,5]

    Output: [5,4,3,2,1]

    Explanation: The reverse of the array [1,2,3,4,5] is [5,4,3,2,1]

    Input: n=6, arr = [1,2,1,1,5,1]

    Output: [1,5,1,1,2,1]

    Explanation: The reverse of the array [1,2,1,1,5,1] is [1,5,1,1,2,1].
*/

#include <iostream>
#include <algorithm> 
using namespace std;

class Solution{
public:
    int i = 0;
    void reverse(int arr[], int n){
        if(i >= n - 1 - i) return;
        swap(arr[i], arr[n - i - 1]);
        i++;
        reverse(arr, n);
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution sol;
    sol.reverse(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    // Output: 5 4 3 2 1

    return 0;
}