/*
    2104. Sum of Subarray Ranges
    You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

    Return the sum of all subarray ranges of nums.

    A subarray is a contiguous non-empty sequence of elements within an array.

    Example 1:

    Input: nums = [1,2,3]
    Output: 4
    Explanation: The 6 subarrays of nums are the following:
    [1], range = largest - smallest = 1 - 1 = 0 
    [2], range = 2 - 2 = 0
    [3], range = 3 - 3 = 0
    [1,2], range = 2 - 1 = 1
    [2,3], range = 3 - 2 = 1
    [1,2,3], range = 3 - 1 = 2
    So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
    Example 2:

    Input: nums = [1,3,3]
    Output: 4
    Explanation: The 6 subarrays of nums are the following:
    [1], range = largest - smallest = 1 - 1 = 0
    [3], range = 3 - 3 = 0
    [3], range = 3 - 3 = 0
    [1,3], range = 3 - 1 = 2
    [3,3], range = 3 - 3 = 0
    [1,3,3], range = 3 - 1 = 2
    So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
    Example 3:

    Input: nums = [4,-2,-3,4,1]
    Output: 59
    Explanation: The sum of all subarray ranges of nums is 59.

    Constraints:

    1 <= nums.length <= 1000
    -109 <= nums[i] <= 109

    Follow-up: Could you find a solution with O(n) time complexity?
*/

#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

class Solution {
public:
    // long long subArrayRanges(vector<int>& nums) {
    //     const int MOD = 1e9 + 7;
    //     int n = nums.size();
    //     long long sum = 0;
    //     for(int i = 0; i < n; i++){
    //         int minElement = nums[i];
    //         int maxElement = nums[i];
    //         for(int j = i + 1; j < n; j++){
    //             minElement = min(minElement, nums[j]);
    //             maxElement = max(maxElement, nums[j]);
    //             sum = (sum + maxElement - minElement) % MOD;
    //         }
    //     }
    //     return sum;
    // }

    long long subArrayRanges(vector<int>& nums) {
        return sumOfSubarrayMax(nums) - sumOfSubarrayMin(nums);
    }

    long long sumOfSubarrayMin(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        stack<int> st;

        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? mid + 1 : mid - st.top();
                int right = i - mid;
                res += 1LL * nums[mid] * left * right;
            }
            st.push(i);
        }
        return res;
    }

    long long sumOfSubarrayMax(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        stack<int> st;

        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || nums[st.top()] < nums[i])) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? mid + 1 : mid - st.top();
                int right = i - mid;
                res += 1LL * nums[mid] * left * right;
            }
            st.push(i);
        }
        return res;
    }
}; 

int main() {
    Solution sol;
    vector<int> nums = {4, -2, -3, 4, 1};
    cout << "Sum of Subarray Ranges: " << sol.subArrayRanges(nums) << endl;
    return 0;
}

// | Metric    | Value   |
// | --------- | ------- |
// | Time      | O(n)    |
// | Space     | O(n)    |
// | Works for | n ≤ 10⁵ |
