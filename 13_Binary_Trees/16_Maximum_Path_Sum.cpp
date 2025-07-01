/*
    124. Binary Tree Maximum Path Sum
    A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

    The path sum of a path is the sum of the node's values in the path.

    Given the root of a binary tree, return the maximum path sum of any non-empty path.

    Example 1:
    Input: root = [1,2,3]
    Output: 6
    Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
    
    Example 2:
    Input: root = [-10,9,20,null,null,15,7]
    Output: 42
    Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
    
    Constraints:

    The number of nodes in the tree is in the range [1, 3 * 104].
    -1000 <= Node.val <= 1000
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int maxGain(TreeNode* node, int& maxi) {
        if (!node) return 0;

        // Max path sum on the left and right, ignore negatives
        int left = max(0, maxGain(node->left, maxi));
        int right = max(0, maxGain(node->right, maxi));

        // Max path including both children + current node (candidate for answer)
        int currentMaxPath = node->val + left + right;

        // Update global max
        maxi = max(maxi, currentMaxPath);

        // Return max sum going upward (only one child can be included in upward path)
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxGain(root, maxi);
        return maxi;
    }
};

// Optional main to test
int main() {
    // Tree: [-10,9,20,null,null,15,7]
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

    Solution sol;
    cout << "Maximum Path Sum: " << sol.maxPathSum(root) << endl;  // Output: 42

    return 0;
}

// Time: O(n) — every node visited once.
// Space: O(h) — recursion stack, h = height of tree