/*
    110. Balanced Binary Tree
    Given a binary tree, determine if it is height-balanced.

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: true

    Example 2:
    Input: root = [1,2,2,3,3,null,null,4,4]
    Output: false

    Example 3:
    Input: root = []
    Output: true
    
    Constraints:

    The number of nodes in the tree is in the range [0, 5000].
    -104 <= Node.val <= 104
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
    // Helper function returns height if balanced, -1 if not balanced
    int checkHeight(TreeNode* node) {
        if (node == nullptr) return 0;

        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1;

        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};

// Optional: Example main function to test
int main() {
    // Example 1: [3,9,20,null,null,15,7] → Balanced
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

    Solution sol;
    cout << "Is tree 1 balanced? " << (sol.isBalanced(root1) ? "Yes" : "No") << endl;  // Output: Yes

    // Example 2: [1,2,2,3,3,null,null,4,4] → Not balanced
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);
    root2->left->left->right = new TreeNode(4);

    cout << "Is tree 2 balanced? " << (sol.isBalanced(root2) ? "Yes" : "No") << endl;  // Output: No

    return 0;
}

// Time: O(n) — every node is visited once.
// Space: O(h) — for recursion stack, where h is the height of the tree.