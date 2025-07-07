#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // No left child, visit current node and move to right
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find inorder predecessor
                TreeNode* pred = curr->left;
                while (pred->right != nullptr && pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == nullptr) {
                    // Make a temporary thread to the current node
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Thread exists, remove it and visit current
                    pred->right = nullptr;
                    result.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return result;
    }
};

// Helper function to build a sample tree
TreeNode* buildSampleTree() {
    // Tree: [1,2,3,4,5,null,8,null,null,6,7,9]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(9);
    return root;
}

// Main function
int main() {
    TreeNode* root = buildSampleTree();
    Solution sol;
    vector<int> inorder = sol.inorderTraversal(root);

    cout << "Morris Inorder Traversal: ";
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// Time: O(n)

// Space: O(1) – no extra stack or recursion, uses threaded tree temporarily