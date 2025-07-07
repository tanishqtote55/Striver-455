/*
    700. Search in a Binary Search Tree
    You are given the root of a binary search tree (BST) and an integer val.
    Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

    Example 1:
    Input: root = [4,2,7,1,3], val = 2
    Output: [2,1,3]

    Example 2:
    Input: root = [4,2,7,1,3], val = 5
    Output: []    

    Constraints:

    The number of nodes in the tree is in the range [1, 5000].
    1 <= Node.val <= 107
    root is a binary search tree.
    1 <= val <= 107
*/

#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class with searchBST method
class Solution {
public:
    // Recursive version
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) {
            return root;
        }
        if (val < root->val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }

    // Iterative version (optional)
    TreeNode* searchBSTIterative(TreeNode* root, int val) {
        while (root != nullptr) {
            if (val == root->val) return root;
            else if (val < root->val) root = root->left;
            else root = root->right;
        }
        return nullptr;
    }
};

// Helper function to print inorder traversal of a tree
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Helper function to build BST manually for testing
TreeNode* createSampleTree() {
    // Tree structure:
    //         4
    //       /   \
    //      2     7
    //     / \
    //    1   3
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    return root;
}

// Main function
int main() {
    TreeNode* root = createSampleTree();
    int target = 5;

    Solution sol;

    TreeNode* result = sol.searchBST(root, target); // or use sol.searchBSTIterative(root, target);
    
    if (result) {
        cout << "Subtree rooted at value " << target << ": ";
        printInorder(result);
    } else {
        cout << "Value " << target << " not found in the BST.";
    }

    cout << endl;
    return 0;
}

// Time & Space Complexity
// Time Complexity: O(h) where h is the height of the BST.
// In best case (balanced BST), O(log n)
// In worst case (skewed BST), O(n)

// Space Complexity:
// Recursive version: O(h) for recursion stack
// Iterative version: O(1)