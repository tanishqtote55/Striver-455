/*
    560. Subarray Sum Equals K
    Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

    A subarray is a contiguous non-empty sequence of elements within an array.

    Example 1:

    Input: nums = [1,1,1], k = 2
    Output: 2
    Example 2:

    Input: nums = [1,2,3], k = 3
    Output: 2
    
    Constraints:

    1 <= nums.length <= 2 * 104
    -1000 <= nums[i] <= 1000
    -107 <= k <= 107
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Brute Force Approach
    // int subarraySum(vector<int>& arr, int k) {
    //     int n = arr.size(); // size of the given array.
    //     int cnt = 0; // Number of subarrays:

    //     for (int i = 0 ; i < n; i++) { // starting index i
    //         for (int j = i; j < n; j++) { // ending index j

    //             // calculate the sum of subarray [i...j]
    //             int sum = 0;
    //             for (int K = i; K <= j; K++)
    //                 sum += arr[K];

    //             // Increase the count if sum == k:
    //             if (sum == k)
    //                 cnt++;
    //         }
    //     }
    //     return cnt;
    // }

    // int subarraySum(vector<int>& arr, int k) {
    //     int n = arr.size(); // size of the given array.
    //     int cnt = 0; // Number of subarrays:

    //     for (int i = 0 ; i < n; i++) { // starting index i
    //         int sum = 0;
    //         for (int j = i; j < n; j++) { // ending index j
    //             // calculate the sum of subarray [i...j]
    //             // sum of [i..j-1] + arr[j]
    //             sum += arr[j];

    //             // Increase the count if sum == k:
    //             if (sum == k)
    //                 cnt++;
    //         }
    //     }
    //     return cnt;
    // }

    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_count;
        prefix_count[0] = 1;
        
        int sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (prefix_count.find(sum - k) != prefix_count.end()) {
                count += prefix_count[sum - k];
            }
            prefix_count[sum]++;
        }
        
        return count;
    }
};

int main() {
    int n, k;
    cout << "Enter size of array: "; 
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
  
    cout << "Enter k: "; 
    cin >> k;

    Solution sol;
    int result = sol.subarraySum(nums, k);
    cout << "Number of subarrays with sum " << k << " = " << result << endl;

    return 0;
}