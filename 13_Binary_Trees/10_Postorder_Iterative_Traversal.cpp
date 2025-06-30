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

// Class with postorder traversal methods
class Solution {
public:

    // Iterative Postorder Traversal
    vector<int> postorderTraversalIterative(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            TreeNode* curr = st1.top();
            st1.pop();
            st2.push(curr);

            if (curr->left) st1.push(curr->left);
            if (curr->right) st1.push(curr->right);
        }

        while (!st2.empty()) {
            result.push_back(st2.top()->val);
            st2.pop();
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

    cout << "Iterative Postorder Traversal: ";
    vector<int> iterativeResult = sol.postorderTraversalIterative(root);
    printVector(iterativeResult);

    // Cleanup
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
