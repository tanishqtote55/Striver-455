/*
    99. Recover Binary Search Tree
    You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

    Example 1:
    Input: root = [1,3,null,null,2]
    Output: [3,1,null,null,2]
    Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

    Example 2:
    Input: root = [3,1,4,null,null,2]
    Output: [2,1,4,null,null,3]
    Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
    
    Constraints:

    The number of nodes in the tree is in the range [2, 1000].
    -231 <= Node.val <= 231 - 1

    Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?
*/

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *middle = nullptr, *last = nullptr, *prev = nullptr;

        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) {
                // Process current node
                if (prev && prev->val > curr->val) {
                    if (!first) {
                        first = prev;
                        middle = curr;
                    } else {
                        last = curr;
                    }
                }
                prev = curr;
                curr = curr->right;
            } else {
                // Morris Traversal: create temporary thread
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr)
                    pred = pred->right;

                if (!pred->right) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = nullptr;
                    if (prev && prev->val > curr->val) {
                        if (!first) {
                            first = prev;
                            middle = curr;
                        } else {
                            last = curr;
                        }
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        // Fix swapped nodes
        if (first && last) {
            swap(first->val, last->val);
        } else if (first && middle) {
            swap(first->val, middle->val);
        }
    }
};

// Insert a node into BST (used for controlled creation, not recovery)
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Inorder traversal to print BST
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    /*
        Let's create a BST with a swapped pair:
        Original BST:      3
                         /   \
                        1     4
                             /
                            2

        Swapped BST: 3 and 2 are swapped => violates BST property
        So tree becomes:
                          2
                         / \
                        1   4
                           /
                          3
    */

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3); // 3 and 2 are swapped

    cout << "Before Recovery (Inorder): ";
    printInorder(root); // Wrong inorder
    cout << endl;

    Solution().recoverTree(root);

    cout << "After Recovery (Inorder): ";
    printInorder(root); // Correct inorder: 1 2 3 4
    cout << endl;

    return 0;
}

// | Metric | Value          |
// | ------ | -------------- |
// | Time   | O(n)           |
// | Space  | O(1) auxiliary |
