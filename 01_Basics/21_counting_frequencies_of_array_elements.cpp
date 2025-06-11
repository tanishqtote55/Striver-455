/*
Count frequency of each element in the array
Problem statement: Given an array, we have found the number of occurrences of each element in the array.

Examples:

Example 1:
Input: arr[] = {10,5,10,15,10,5};
Output: 10  3
	 5  2
        15  1
Explanation: 10 occurs 3 times in the array
	      5 occurs 2 times in the array
              15 occurs 1 time in the array

Example2: 
Input: arr[] = {2,2,3,4,4,2};
Output: 2  3
	3  1
        4  2
Explanation: 2 occurs 3 times in the array
	     3 occurs 1 time in the array
             4 occurs 2 time in the array
*/

#include <iostream>
#include <unordered_map>

using namespace std;

void Frequency(int arr[], int n) {
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++){
        map[arr[i]]++;
    }
    for(auto it: map){
        cout << it.first << " -> " << it.second << endl;
    }

}

int main() {
    int arr[] = {10,5,10,15,10,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Frequency(arr, n);
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(n)




// #include <iostream>
// using namespace std;
// void countFreq(int arr[], int n)
// {
//     vector<bool> visited(n, false);
//     for (int i = 0; i < n; i++) {
//         // Skip this element if already processed
//         if (visited[i] == true)
//             continue;
//         // Count frequency
//         int count = 1;
//         for (int j = i + 1; j < n; j++) {
//             if (arr[i] == arr[j]) {
//                 visited[j] = true;
//                 count++;
//             }
//         }
//         cout << arr[i] << " " << count << endl;
//     }
// }
// int main()
// {
//     int arr[] = {10,5,10,15,10,5};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     countFreq(arr, n);
//     return 0;
// }