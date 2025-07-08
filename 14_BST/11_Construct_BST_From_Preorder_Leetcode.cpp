/*
    1008. Construct Binary Search Tree from Preorder Traversal
    Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.
    It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
    A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.
    A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

    Example 1:
    Input: preorder = [8,5,1,7,10,12]
    Output: [8,5,10,1,7,null,12]
    
    Example 2:
    Input: preorder = [1,3]
    Output: [1,null,3]
    
    Constraints:

    1 <= preorder.length <= 100
    1 <= preorder[i] <= 1000
    All the values of preorder are unique.
*/

// 1st Logic => Sort Preorder = Get Inorder and From Inorder and Preorder Form Unique BT

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return build(preorder, index, INT_MIN, INT_MAX);
    }

private:
    TreeNode* build(vector<int>& preorder, int& index, int minVal, int maxVal) {
        if (index >= preorder.size()) return nullptr;

        int val = preorder[index];
        if (val < minVal || val > maxVal) return nullptr;

        TreeNode* root = new TreeNode(val);
        index++;
        root->left = build(preorder, index, minVal, val - 1);
        root->right = build(preorder, index, val + 1, maxVal);
        return root;
    }
};

// Helper function to print inorder (for testing)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution sol;

    // Example 1
    vector<int> preorder1 = {8, 5, 1, 7, 10, 12};
    TreeNode* root1 = sol.bstFromPreorder(preorder1);
    cout << "Inorder traversal of tree 1: ";
    inorder(root1);
    cout << endl;

    // Example 2
    vector<int> preorder2 = {1, 3};
    TreeNode* root2 = sol.bstFromPreorder(preorder2);
    cout << "Inorder traversal of tree 2: ";
    inorder(root2);
    cout << endl;

    return 0;
}

// Time & Space Complexity:
// Time: O(n), where n is the number of nodes.
// Space: O(h), recursion stack (height of BST).