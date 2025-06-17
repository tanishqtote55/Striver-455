/*
Count Occurrences in Sorted Array

Problem Statement: You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.

Example 1:
Input: N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
Output: 4
Explanation: 3 is occurring 4 times in 
the given array so it is our answer.

Example 2:
Input: N = 8,  X = 2 , array[] = {1, 1, 2, 2, 2, 2, 2, 3}
Output: 5
Explanation: 2 is occurring 5 times in the given array so it is our answer.
*/


#include<iostream>
#include<vector>

using namespace std;

// int count(vector<int>& arr, int n, int x) {
//     int cnt = 0;
//     for (int i = 0; i < n; i++) {

//         // counting the occurrences:
//         if (arr[i] == x) cnt++;
//     }
//     return cnt;
// }

int count(vector<int>& arr, int n, int x) {
    int first = -1;
    int last = -1;
    int left = 0;
    int right = n - 1;

    // First occurrence
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            first = mid;
            right = mid - 1;
        }
        else if (arr[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    left = 0;
    right = n - 1;

    // Last occurrence
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            last = mid;
            left = mid + 1;
        }
        else if (arr[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    if (first == -1 && last == -1) 
        return 0;
    return last - first + 1;
}

int main() {
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, x = 8;
    int ans = count(arr, n, x);
    cout << "The number of occurrences is: "
         << ans << "\n";
    return 0;
}

