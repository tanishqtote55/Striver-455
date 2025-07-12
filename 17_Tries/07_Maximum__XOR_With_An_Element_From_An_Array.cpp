/*
    1707. Maximum XOR With an Element From Array
    You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].
    The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.
    Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

    Example 1:
    Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
    Output: [3,3,7]
    Explanation:
    1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
    2) 1 XOR 2 = 3.
    3) 5 XOR 2 = 7.

    Example 2:
    Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
    Output: [15,-1,5]
    
    Constraints:

    1 <= nums.length, queries.length <= 105
    queries[i].length == 2
    0 <= nums[j], xi, mi <= 109
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

class TrieNode {
public:
    TrieNode* child[2];
    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit])
                node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
    }

    int getMaxXOR(int x) {
        TrieNode* node = root;
        if (!node->child[0] && !node->child[1]) return -1;

        int maxXOR = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int opp = 1 - bit;
            if (node->child[opp]) {
                maxXOR |= (1 << i);
                node = node->child[opp];
            } else {
                node = node->child[bit];
            }
        }
        return maxXOR;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<tuple<int, int, int>> offlineQueries;
        for (int i = 0; i < queries.size(); ++i) {
            offlineQueries.emplace_back(queries[i][1], queries[i][0], i); // {mi, xi, index}
        }

        sort(offlineQueries.begin(), offlineQueries.end());

        Trie trie;
        vector<int> result(queries.size());
        int i = 0;

        for (const auto& t : offlineQueries) {
            int mi = get<0>(t);
            int xi = get<1>(t);
            int idx = get<2>(t);

            while (i < nums.size() && nums[i] <= mi) {
                trie.insert(nums[i]);
                i++;
            }

            result[idx] = trie.getMaxXOR(xi);
        }

        return result;
    }
};

// ---------------------- MAIN FUNCTION ----------------------

int main() {
    Solution sol;

    vector<int> nums1 = {0, 1, 2, 3, 4};
    vector<vector<int>> queries1 = {{3, 1}, {1, 3}, {5, 6}};
    vector<int> result1 = sol.maximizeXor(nums1, queries1);
    cout << "Output 1: ";
    for (int val : result1) cout << val << " ";
    cout << endl;

    vector<int> nums2 = {5, 2, 4, 6, 6, 3};
    vector<vector<int>> queries2 = {{12, 4}, {8, 1}, {6, 3}};
    vector<int> result2 = sol.maximizeXor(nums2, queries2);
    cout << "Output 2: ";
    for (int val : result2) cout << val << " ";
    cout << endl;

    return 0;
}

// Time:
// Sorting nums: O(n log n)
// Sorting queries: O(q log q)
// Trie insertions & lookups: O(32 * (n + q)) ≈ O(n + q)
// Total: O(n log n + q log q)

// Space:
// Trie: O(n * 32) → each number has up to 32 bits
// Result: O(q)
// Total: O(n + q)