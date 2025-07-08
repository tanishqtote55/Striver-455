/*
    Inorder successor and predecessor in BST
    Given the root node of a binary search tree (BST) and an integer key. Return the Inorder predecessor and successor of the given key from the provided BST.
    If predecessor or successor is missing then return -1.

    Examples:
    Input : root = [5, 2, 10, 1, 4, 7, 12] , key = 10
    Output : [7, 12]
    Explanation :

    Input : root = [5, 2, 10, 1, 4, 7, 12] , key = 12
    Output : [10, -1]
    Explanation :
*/

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> succPredBST(TreeNode* root, int key) {
        TreeNode* pred = nullptr;
        TreeNode* succ = nullptr;
        TreeNode* current = root;

        // Step 1: Search for the node with the given key, track potential pred/succ
        while (current) {
            if (key < current->data) {
                succ = current;
                current = current->left;
            } else if (key > current->data) {
                pred = current;
                current = current->right;
            } else {
                break; // Found key
            }
        }

        // Step 2: If key is found, find predecessor and successor in subtrees
        if (current) {
            // Predecessor: rightmost node in left subtree
            if (current->left) {
                TreeNode* temp = current->left;
                while (temp->right) temp = temp->right;
                pred = temp;
            }

            // Successor: leftmost node in right subtree
            if (current->right) {
                TreeNode* temp = current->right;
                while (temp->left) temp = temp->left;
                succ = temp;
            }
        }

        return {pred ? pred->data : -1, succ ? succ->data : -1};
    }
};

// Helper function to insert into BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

int main() {
    // Build BST: [5, 2, 10, 1, 4, 7, 12]
    vector<int> values = {5, 2, 10, 1, 4, 7, 12};
    TreeNode* root = nullptr;
    for (int val : values) {
        root = insert(root, val);
    }

    Solution sol;

    // Test 1
    int key1 = 10;
    vector<int> result1 = sol.succPredBST(root, key1);
    cout << "Predecessor and Successor of " << key1 << " are: ";
    cout << result1[0] << " " << result1[1] << endl;

    // Test 2
    int key2 = 12;
    vector<int> result2 = sol.succPredBST(root, key2);
    cout << "Predecessor and Successor of " << key2 << " are: ";
    cout << result2[0] << " " << result2[1] << endl;

    // Test 3
    int key3 = 5;
    vector<int> result3 = sol.succPredBST(root, key3);
    cout << "Predecessor and Successor of " << key3 << " are: ";
    cout << result3[0] << " " << result3[1] << endl;

    return 0;
}

// Time & Space Complexity:
// Time: O(h) — height of BST
// Space: O(1) — no extra space used