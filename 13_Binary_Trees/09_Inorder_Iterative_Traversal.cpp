#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Class with inorder traversal methods
class Solution {
public:

    // Iterative Inorder Traversal
    vector<int> inorderTraversalIterative(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            result.push_back(curr->val);  // Visit node
            curr = curr->right;
        }

        return result;
    }
};

// Helper function to print a vector
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// Main function for testing
int main() {
    /*
         1
          \
           2
          /
         3
    */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;

    cout << "Iterative Inorder Traversal: ";
    vector<int> iterativeResult = sol.inorderTraversalIterative(root);
    printVector(iterativeResult);

    // Cleanup
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
