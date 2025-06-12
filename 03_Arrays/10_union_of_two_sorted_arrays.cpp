/*
    Union of two sorted arrays
    Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. The elements in the union must be in ascending order.

    The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.

    Examples:
    Input: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]

    Output: [1, 2, 3, 4, 5, 7]

    Explanation: The elements 1, 2 are common to both, 3, 4, 5 are from nums1 and 7 is from nums2

    Input: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]

    Output: [1, 3, 4, 5, 6, 7, 8, 9]

    Explanation: The element 7 is common to both, 3, 4, 6, 9 are from nums1 and 1, 5, 8 is from nums2
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();

        while (i < n && j < m) {
            // If both are equal
            if (nums1[i] == nums2[j]) {
                if (result.empty() || result.back() != nums1[i])
                    result.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]) {
                if (result.empty() || result.back() != nums1[i])
                    result.push_back(nums1[i]);
                i++;
            }
            else {
                if (result.empty() || result.back() != nums2[j])
                    result.push_back(nums2[j]);
                j++;
            }
        }

        // Remaining elements of nums1
        while (i < n) {
            if (result.empty() || result.back() != nums1[i])
                result.push_back(nums1[i]);
            i++;
        }

        // Remaining elements of nums2
        while (j < m) {
            if (result.empty() || result.back() != nums2[j])
                result.push_back(nums2[j]);
            j++;
        }

        return result;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {1, 2, 7};

    Solution sol;
    vector<int> result = sol.unionArray(nums1, nums2);

    cout << "Union of arrays without duplicates: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}