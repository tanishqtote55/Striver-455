/*
    98. Validate Binary Search Tree
    Given the root of a binary tree, determine if it is a valid binary search tree (BST).
    A valid BST is defined as follows:
    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
    
    Example 1:
    Input: root = [2,1,3]
    Output: true
    
    Example 2:
    Input: root = [5,1,4,null,null,3,6]
    Output: false
    Explanation: The root node's value is 5 but its right child's value is 4.

    Constraints:

    The number of nodes in the tree is in the range [1, 104].
    -231 <= Node.val <= 231 - 1
*/

#include <iostream>
#include <climits>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode* node, long minVal, long maxVal) {
        if (!node) return true;

        if (node->val <= minVal || node->val >= maxVal)
            return false;

        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    }
};

// Helper to insert nodes (used only if building BST; not used in this test)
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Test cases
int main() {
    Solution sol;

    // Example 1: root = [2,1,3]
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    cout << "Example 1: " << (sol.isValidBST(root1) ? "true" : "false") << endl; // Output: true

    // Example 2: root = [5,1,4,null,null,3,6]
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);
    cout << "Example 2: " << (sol.isValidBST(root2) ? "true" : "false") << endl; // Output: false

    return 0;
}

// Time & Space Complexity:
// Time: O(n), where n is the number of nodes.
// Space: O(h), recursion stack height (O(log n) for balanced BST, O(n) worst case).