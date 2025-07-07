#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Find minimum value in BST (leftmost node)
    int findMin(TreeNode* root) {
        if (root == nullptr) {
            throw runtime_error("Tree is empty");
        }

        TreeNode* current = root;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current->val;
    }

    // Find maximum value in BST (rightmost node)
    int findMax(TreeNode* root) {
        if (root == nullptr) {
            throw runtime_error("Tree is empty");
        }

        TreeNode* current = root;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current->val;
    }
};

// Helper function to manually create a BST
TreeNode* createSampleTree() {
    // Tree structure:
    //         8
    //       /   \
    //      4     12
    //     / \    / \
    //    2   6  10  14
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();

    Solution sol;
    try {
        int minValue = sol.findMin(root);
        int maxValue = sol.findMax(root);

        cout << "Minimum value in BST: " << minValue << endl;
        cout << "Maximum value in BST: " << maxValue << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

// Time Complexity: O(log N) on average for balanced BST, O(N) in worst case (skewed).

// Space Complexity: O(1) (no extra space used).