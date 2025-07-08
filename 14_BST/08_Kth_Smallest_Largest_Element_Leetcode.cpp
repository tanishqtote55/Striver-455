/*
    230. Kth Smallest Element in a BST
    Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

    Example 1:
    Input: root = [3,1,4,null,2], k = 1
    Output: 1
    
    Example 2:
    Input: root = [5,3,6,2,4,null,null,1], k = 3
    Output: 3

    Constraints:

    The number of nodes in the tree is n.
    1 <= k <= n <= 104
    0 <= Node.val <= 104
    
    Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
*/

#include <iostream>
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
    int count = 0;
    int result = -1;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
private:
    void inorder(TreeNode* node, int k) {
        if (!node || result != -1) return;
        inorder(node->left, k);
        count++;
        if (count == k) {
            result = node->val;
            return;
        }
        inorder(node->right, k);
    }
};

// class Solution {
// public:
//     int count = 0;
//     int result = -1;
//     int kthLargest(TreeNode* root, int k) {
//         reverseInorder(root, k);
//         return result;
//     }
// private:
//     void reverseInorder(TreeNode* node, int k) {
//         if (!node || result != -1) return;
//         reverseInorder(node->right, k);  // Visit right subtree first
//         count++;
//         if (count == k) {
//             result = node->val;
//             return;
//         }
//         reverseInorder(node->left, k);  // Then visit left subtree
//     }
// };

// Helper functions for testing
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Build BST: [5,3,6,2,4,null,null,1]
    TreeNode* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 1);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    int k = 2;
    Solution sol;
    int kth = sol.kthSmallest(root, k);

    cout << k << "-th smallest element: " << kth << endl;

    return 0;
}

// Time and Space Complexity:
// Time: O(k) in best case (early stop) up to O(n) in worst case.
// Space: O(h) where h is height of tree (due to recursion stack); O(log n) in balanced, O(n) in skewed.