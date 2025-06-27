/*
    503. Next Greater Element II
    Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

    The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

    Example 1:

    Input: nums = [1,2,1]
    Output: [2,-1,2]
    Explanation: The first 1's next greater number is 2; 
    The number 2 can't find next greater number. 
    The second 1's next greater number needs to search circularly, which is also 2.
    Example 2:

    Input: nums = [1,2,3,4,3]
    Output: [2,3,4,-1,4]    

    Constraints:

    1 <= nums.length <= 104
    -109 <= nums[i] <= 109
*/
 
// Circular Array => Double the Array Hypothetically using Module Operator 

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // vector<int> nextGreaterElements(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> result(n, -1);

    //     for (int i = 0; i < n; ++i) {
    //         // Search next n - 1 elements in circular order
    //         for (int j = i + 1; j <= i + n - 1; ++j) {
    //             int nextIdx = j % n;
    //             if (nums[nextIdx] > nums[i]) {
    //                 result[i] = nums[nextIdx];
    //                 break;
    //             }
    //         }
    //     }

    //     return result;
    // }

    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);  // Initialize result with -1
        stack<int> st;              // Stack stores **indices**

        // Traverse twice to simulate circular behavior
        for (int i = 2 * n - 1; i >= 0; --i) {
            int index = i % n;

            // Maintain decreasing stack
            while (!st.empty() && nums[st.top()] <= nums[index]) {
                st.pop();
            }

            // Only fill result during the first pass (i < n)
            if (i < n) {
                result[index] = st.empty() ? -1 : nums[st.top()];
            }

            st.push(index);  // Push current index
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums = {1, 2, 1};

    vector<int> result = sol.nextGreaterElements(nums);

    cout << "Next greater elements:\n";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

// | Metric           | Value        |
// | ---------------- | ------------ |
// | Time Complexity  | O(2N) = O(N) |
// | Space Complexity | O(N)         |
