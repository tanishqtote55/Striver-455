// Morris traversal allows O(1) space traversal (i.e., no recursion or stack) by temporarily modifying the tree's structure (creating threads to predecessors).

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // If no left child, process current node and move to right
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find the inorder predecessor
                TreeNode* pred = curr->left;
                while (pred->right != nullptr && pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == nullptr) {
                    // Make a temporary link (thread), visit current
                    pred->right = curr;
                    result.push_back(curr->val);  // Visit before going left (preorder)
                    curr = curr->left;
                } else {
                    // Thread already exists, remove it and go right
                    pred->right = nullptr;
                    curr = curr->right;
                }
            }
        }

        return result;
    }
};

// Main
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(9);
    Solution sol;
    vector<int> preorder = sol.preorderTraversal(root);

    cout << "Morris Preorder Traversal: ";
    for (int val : preorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// Time: O(n)

// Space: O(1) – no extra stack or recursion, uses threaded tree temporarily