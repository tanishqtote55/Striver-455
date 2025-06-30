// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    // Iterative Preorder Traversal
    vector<int> preorderTraversalIterative(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            result.push_back(curr->val);

            if (curr->right) st.push(curr->right);
            if (curr->left) st.push(curr->left);
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
    
    cout << "Iterative Preorder Traversal: ";
    vector<int> iterativeResult = sol.preorderTraversalIterative(root);
    printVector(iterativeResult);

    // Cleanup
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}