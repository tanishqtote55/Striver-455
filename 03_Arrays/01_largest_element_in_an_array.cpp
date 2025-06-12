/*
    Largest Element
    Given an array of integers nums, return the value of the largest element in the array

    Examples:
    Input: nums = [3, 3, 6, 1]

    Output: 6

    Explanation: The largest element in array is 6

    Input: nums = [3, 3, 0, 99, -40]

    Output: 99

    Explanation: The largest element in array is 99
*/


#include <iostream>
 
using namespace std;

// Brute Force Approach
// Sorting and Printing Last Element

// For Loop Using a Max Variable
int findLargestElement(int arr[], int n) {
 
  int max = arr[0];
  for (int i = 0; i < n; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}
int main() {
  int arr1[] = {2,5,1,3,0};
  int n = 5;
  int max = findLargestElement(arr1, n);
  cout << "The largest element in the array is: " << max << endl;
 
  int arr2[] =  {8,10,5,7,9};
  n = 5;
  max = findLargestElement(arr2, n);
  cout << "The largest element in the array is: " << max<<endl;
  return 0;
}


