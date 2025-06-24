/*
    Single Number - III
    Given an array nums of length n, every integer in the array appears twice except for two integers. Identify and return the two integers that appear only once in the array. Return the two numbers in ascending order.

    For example, if nums = [1, 2, 1, 3, 5, 2], the correct answer is [3, 5], not [5, 3].

    Examples:
    Input : nums = [1, 2, 1, 3, 5, 2]

    Output : [3, 5]

    Explanation : The integers 3 and 5 have appeared only once.

    Input : nums = [-1, 0]

    Output : [-1, 0]

    Explanation : The integers -1 and 0 have appeared only once.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {	
public:		
    // Time Complexity: O(2N), Space: O(1)
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;

        // Step 1: XOR all numbers to get a ^ b
        for (int num : nums) {
            xr ^= num;
        }

        // Step 2: Get rightmost set bit in a ^ b
        // int rightmost = (xr & (xr - 1)) ^ xr;
        int rightmost = xr & -xr;  // or: (xr & (xr - 1)) ^ xr

        // Step 3: Divide elements into two buckets
        int b1 = 0, b2 = 0;
        for (int num : nums) {
            if (num & rightmost)
                b1 ^= num;
            else
                b2 ^= num;
        }

        return {b1, b2};  // order doesn't matter
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (all appear twice except two):\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution sol;
    vector<int> result = sol.singleNumber(nums);

    cout << "The two non-repeating elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
