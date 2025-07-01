/*
    543. Diameter of Binary Tree
    Given the root of a binary tree, return the length of the diameter of the tree.
    The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
    The length of a path between two nodes is represented by the number of edges between them.

    Example 1:

    Input: root = [1,2,3,4,5]
    Output: 3
    Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
    
    Example 2:
    Input: root = [1,2]
    Output: 1

    Constraints:

    The number of nodes in the tree is in the range [1, 104].
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
    int height(TreeNode* node, int& diameter) {
        if (!node) return 0;

        int left = height(node->left, diameter);
        int right = height(node->right, diameter);

        // Update the diameter at this node
        diameter = max(diameter, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};

// Optional main to test
int main() {
    // Tree: [1,2,3,4,5]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3);

    Solution sol;
    cout << "Diameter: " << sol.diameterOfBinaryTree(root) << endl;  // Output: 3

    return 0;
}

// Time Complexity: O(n) — each node is visited once.
// Space Complexity: O(h) — recursion stack depth (h = tree height).