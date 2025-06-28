/*
    1248. Count Number of Nice Subarrays
    Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
    Return the number of nice sub-arrays.

    Example 1:

    Input: nums = [1,1,2,1,1], k = 3
    Output: 2
    Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
    Example 2:

    Input: nums = [2,4,6], k = 1
    Output: 0
    Explanation: There are no odd numbers in the array.
    Example 3:

    Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
    Output: 16

    Constraints:

    1 <= nums.length <= 50000
    1 <= nums[i] <= 10^5
    1 <= k <= nums.length
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to count subarrays with at most k odd numbers
    int atMost(vector<int>& nums, int k) {
        int left = 0, count = 0, oddCount = 0;

        for (int right = 0; right < nums.size(); ++right) {
            // Increment oddCount if nums[right] is odd
            if (nums[right] % 2 == 1)
                oddCount++;

            // Shrink window if oddCount exceeds k
            while (oddCount > k) {
                if (nums[left] % 2 == 1)
                    oddCount--;
                left++;
            }

            // All subarrays ending at right and starting from left..right are valid
            count += right - left + 1;
        }

        return count;
    }

    // Main function to get number of subarrays with exactly k odd numbers
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 1, 2, 1, 1};
    int k1 = 3;
    cout << "Test Case 1:\nInput: [1, 1, 2, 1, 1], k = 3\n";
    cout << "Output: " << sol.numberOfSubarrays(nums1, k1) << "\n\n"; // Expected: 2

    vector<int> nums2 = {2, 4, 6};
    int k2 = 1;
    cout << "Test Case 2:\nInput: [2, 4, 6], k = 1\n";
    cout << "Output: " << sol.numberOfSubarrays(nums2, k2) << "\n\n"; // Expected: 0

    vector<int> nums3 = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int k3 = 2;
    cout << "Test Case 3:\nInput: [2,2,2,1,2,2,1,2,2,2], k = 2\n";
    cout << "Output: " << sol.numberOfSubarrays(nums3, k3) << "\n"; // Expected: 16

    return 0;
}