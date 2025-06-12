/*
Problem Statement: Given an array of size n, write a program to check if the given array is sorted in (ascending / Increasing / Non-decreasing) order or not. If the array is sorted then return True, Else return False.

Note: Two consecutive equal values are considered to be sorted.
*/


#include <iostream>
using namespace std;

// bool isSorted(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//         if (arr[j] < arr[i])
//             return false;
//         }
//     }
//     return true;
// }

bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])
        return false;
    }
    return true;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}, n = 5;
    bool ans = isSorted(arr, n);
    if (ans) cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}

