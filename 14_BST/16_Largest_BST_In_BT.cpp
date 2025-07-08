/*
    Largest BST in Binary Tree
    Given a root of Binary Tree, where the nodes have integer values. Return the size of the largest subtree of the binary tree which is also a BST.

    A binary search tree (BST) is a binary tree data structure which has the following properties.

    The left subtree of a node contains only nodes with data less than the node’s data.
    The right subtree of a node contains only nodes with data greater than the node’s data.
    Both the left and right subtrees must also be binary search trees.

    Examples:
    Input : root = [2, 1, 3]
    Output : 3
    Explanation : The given complete binary tree is a BST consisting of 3 nodes.

    Input : root = [10, null, 20, null, 30, null, 40, null, 50]
    Output : 5
    Explanation : If we consider the node 10 as root node then it forms the largest BST.
*/

#include <iostream>
using namespace std;
#include <climits>

struct Info {
    bool isBST;
    int size;
    int minVal;
    int maxVal;

    Info(bool isBST, int size, int minVal, int maxVal)
        : isBST(isBST), size(size), minVal(minVal), maxVal(maxVal) {}
};

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    int maxBSTSize = 0;

    Info dfs(TreeNode* node) {
        if (!node)
            return Info(true, 0, INT_MAX, INT_MIN);

        Info left = dfs(node->left);
        Info right = dfs(node->right);

        if (left.isBST && right.isBST &&
            node->data > left.maxVal && node->data < right.minVal) {

            int currSize = 1 + left.size + right.size;
            maxBSTSize = max(maxBSTSize, currSize);

            return Info(true, currSize,
                        min(node->data, left.minVal),
                        max(node->data, right.maxVal));
        }

        return Info(false, 0, 0, 0); // invalid BST
    }

public:
    int largestBST(TreeNode* root) {
        dfs(root);
        return maxBSTSize;
    }
};

TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    /*
        Example tree:
               10
                 \
                 20
                   \
                   30
                     \
                     40
                       \
                       50

        It's a valid BST → Size = 5
    */

    TreeNode* root = newNode(10);
    root->right = newNode(20);
    root->right->right = newNode(30);
    root->right->right->right = newNode(40);
    root->right->right->right->right = newNode(50);

    Solution sol;
    cout << "Largest BST size: " << sol.largestBST(root) << endl;

    return 0;
}


// | Metric | Value                                       |
// | ------ | ------------------------------------------- |
// | Time   | O(n) – Each node visited once               |
// | Space  | O(h) – Recursive stack (h = height of tree) |
