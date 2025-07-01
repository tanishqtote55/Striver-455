/*
    104. Maximum Depth of Binary Tree
    Given the root of a binary tree, return its maximum depth.

    A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: 3

    Example 2:
    Input: root = [1,null,2]
    Output: 2
    
    Constraints:

    The number of nodes in the tree is in the range [0, 104].
    -100 <= Node.val <= 100
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return 1 + max(leftDepth, rightDepth);
    }
};

// Optional: Simple main to test the function
int main() {
    // Create the tree: [3,9,20,null,null,15,7]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Maximum depth: " << sol.maxDepth(root) << endl;  // Output should be 3

    // Cleanup (not strictly necessary for small test cases but good practice)
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}

// Time Complexity: O(n) — each node is visited once.
// Space Complexity: O(h) — due to the recursion stack, where h is the height of the tree (O(log n) for balanced, O(n) worst-case unbalanced).