/*
    Second Largest Element
    Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.

    Examples:
    Input: nums = [8, 8, 7, 6, 5]

    Output: 7

    Explanation: The largest value in nums is 8, the second largest is 7

    Input: nums = [10, 10, 10, 10, 10]

    Output: -1

    Explanation: The only value in nums is 10, so there is no second largest value, thus -1 is returned
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    // Brute Force Approach
    // Sort then Find Second largest element in the remaining array using loop with break statement {1, 2, 5, 7, 7}

    // One for loop for both largest and second largest as well
    int secondLargestElement(vector<int>& nums) {
        //your code goes here
        if(nums.size() < 2) return -1;
        int largest = INT_MIN;
        int second_largest = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > largest){
                second_largest = largest;
                largest = nums[i];
            }
            else if (nums[i] > second_largest && nums[i] != largest){
                second_largest = nums[i];
            }
        }    
        return (second_largest == INT_MIN) ? -1 : second_largest;    
    }
    int secondSmallestElement(vector<int>& nums) {
        if(nums.size() < 2) return -1;
        int smallest = INT_MAX;
        int second_smallest = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < smallest) {
                second_smallest = smallest;
                smallest = nums[i];
            }
            else if (nums[i] < second_smallest && nums[i] != smallest) {
                second_smallest = nums[i];
            }
        }
        return (second_smallest == INT_MAX) ? -1 : second_smallest;
    }
};

int main() {
    int arr[] = {1, 2, 4, 7, 7, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> nums(arr, arr + n);
    Solution sol;

    int sS = sol.secondSmallestElement(nums);
    int sL = sol.secondLargestElement(nums);

    cout << "Second smallest is " << sS << endl;
    cout << "Second largest is " << sL << endl;

    return 0;
}

