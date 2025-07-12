/*
    421. Maximum XOR of Two Numbers in an Array
    Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

    Example 1:
    Input: nums = [3,10,5,25,2,8]
    Output: 28
    Explanation: The maximum result is 5 XOR 25 = 28.

    Example 2:
    Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
    Output: 127
    
    Constraints:

    1 <= nums.length <= 2 * 105
    0 <= nums[i] <= 231 - 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TrieNode {
public:
    TrieNode* child[2];

    TrieNode() {
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

class Solution {
private:
    TrieNode* root;

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit])
                node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
    }

    int getMaxXOR(int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opp = 1 - bit;
            if (node->child[opp]) {
                maxXor |= (1 << i);
                node = node->child[opp];
            } else {
                node = node->child[bit];
            }
        }
        return maxXor;
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        int maxResult = 0;

        // Insert the first number
        insert(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            maxResult = max(maxResult, getMaxXOR(nums[i]));
            insert(nums[i]);
        }

        return maxResult;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 10, 5, 25, 2, 8};
    cout << "Maximum XOR (Test 1): " << sol.findMaximumXOR(nums1) << endl;

    vector<int> nums2 = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    cout << "Maximum XOR (Test 2): " << sol.findMaximumXOR(nums2) << endl;

    return 0;
}

// Time Complexity: O(n * 32) = O(n)
// Space Complexity: O(n * 32) = O(n)