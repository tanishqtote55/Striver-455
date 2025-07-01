/*
    Boundary Traversal
    Given a root of Binary Tree, perform the boundary traversal of the tree. 

    The boundary traversal is the process of visiting the boundary nodes of the binary tree in the anticlockwise direction, starting from the root.

    The boundary of a binary tree is the concatenation of the root, the left boundary, the leaves ordered from left-to-right, and the reverse order of the right boundary.

    The left boundary is the set of nodes defined by the following:

    The root node's left child is in the left boundary. If the root does not have a left child, then the left boundary is empty.
    If a node in the left boundary and has a left child, then the left child is in the left boundary.
    If a node is in the left boundary, has no left child, but has a right child, then the right child is in the left boundary.
    The leftmost leaf is not in the left boundary.
    The right boundary is similar to the left boundary, except it is the right side of the root's right subtree. Again, the leaf is not part of the right boundary, and the right boundary is empty if the root does not have a right child.

    Examples:
    Input : root = [1, 2, 3, 4, 5, 6, 7, null, null, 8, 9]

    Output : [1, 2, 4, 8, 9, 6, 7, 3]

    Explanation :

    Input : root = [1, 2, null, 4, 9, 6, 5, 3, null, null, null, null, null, 7, 8]

    Output : [1, 2, 4, 6, 5, 7, 8]

    Explanation :
*/

// 1. Overall Strategy: Anti-Clockwise
// Add the root (if not a leaf).
// Add left boundary (excluding leaves).
// Add all leaf nodes (left to right).
// Add right boundary in reverse (excluding leaves).

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class Solution {
public:
    bool isLeaf(TreeNode* node) {
        return !node->left && !node->right;
    }

    void addLeftBoundary(TreeNode* node, vector<int>& res) {
        TreeNode* curr = node->left;
        while (curr) {
            if (!isLeaf(curr)) res.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void addLeaves(TreeNode* node, vector<int>& res) {
        if (!node) return;
        if (isLeaf(node)) {
            res.push_back(node->data);
            return;
        }
        addLeaves(node->left, res);
        addLeaves(node->right, res);
    }

    void addRightBoundary(TreeNode* node, vector<int>& res) {
        TreeNode* curr = node->right;
        vector<int> tmp;
        while (curr) {
            if (!isLeaf(curr)) tmp.push_back(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        reverse(tmp.begin(), tmp.end());
        for (int val : tmp) res.push_back(val);
    }

    vector<int> boundary(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        if (!isLeaf(root)) res.push_back(root->data);

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};

// 🧪 Main function to test the solution
int main() {
    /*
        Construct the tree:
                1
              /   \
             2     3
            / \   / \
           4   5 6   7
              / \
             8   9
        Expected Output: [1, 2, 4, 8, 9, 6, 7, 3]
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<int> result = sol.boundary(root);

    cout << "Boundary Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// Time: O(n), where n = number of nodes (every node visited once).
// Space: O(n), for the result vector and recursion stack (in worst case).