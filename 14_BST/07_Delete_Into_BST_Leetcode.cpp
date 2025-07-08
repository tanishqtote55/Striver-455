/*
    450. Delete Node in a BST
    Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
    Basically, the deletion can be divided into two stages:
    Search for a node to remove.
    If the node is found, delete the node.

    Example 1:

    Input: root = [5,3,6,2,4,null,7], key = 3
    Output: [5,4,6,2,null,null,7]
    Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
    One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
    Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

    Example 2:

    Input: root = [5,3,6,2,4,null,7], key = 0
    Output: [5,3,6,2,4,null,7]
    Explanation: The tree does not contain a node with value = 0.
    Example 3:

    Input: root = [], key = 0
    Output: []
    
    Constraints:

    The number of nodes in the tree is in the range [0, 104].
    -105 <= Node.val <= 105
    Each node has a unique value.
    root is a valid binary search tree.
    -105 <= key <= 105

    Follow up: Could you solve it with time complexity O(height of tree)?
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);  // search in left subtree
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);  // search in right subtree
        } else {
            // Node to be deleted is found
            if (!root->left && !root->right) {
                // Case 1: No children (leaf node)
                delete root;
                return nullptr;
            } else if (!root->left) {
                // Case 2: Only right child
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                // Case 2: Only left child
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                // Case 3: Two children
                TreeNode* successor = getMin(root->right);
                root->val = successor->val;  // Copy successor's value
                root->right = deleteNode(root->right, successor->val);  // Delete successor
            }
        }
        return root;
    }

private:
    TreeNode* getMin(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
};

// Example usage (you can adapt this for testing)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Helper to insert nodes into BST (for testing)
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

int main() {
    Solution sol;
    
    // Build BST: [5,3,6,2,4,null,7]
    TreeNode* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    int key = 3;
    root = sol.deleteNode(root, key);

    cout << "Inorder after deletion of " << key << ": ";
    inorder(root);
    cout << endl;

    return 0;
}

// Time Complexity:
// Best/Average: O(log n) — when the tree is balanced.
// Worst: O(n) — in skewed trees (like a linked list).

// Space Complexity:
// O(h) for recursion stack, where h is the height of the tree.