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

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> st;
        TreeNode* current = root;
        TreeNode* lastVisited = nullptr;

        while (current || !st.empty()) {
            if (current) {
                st.push(current);
                current = current->left;
            } else {
                TreeNode* peekNode = st.top();
                // if right child exists and traversing node from left child, move to right child
                if (peekNode->right && lastVisited != peekNode->right) {
                    current = peekNode->right;
                } else {
                    result.push_back(peekNode->val);
                    lastVisited = peekNode;
                    st.pop();
                }
            }
        }

        return result;
    }
};

// Helper to print vector
void printVector(const vector<int>& vec) {
    for (int val : vec)
        cout << val << " ";
    cout << endl;
}

// Main function for testing
int main() {
    /*
        Sample tree:
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
    vector<int> postorder = sol.postorderTraversal(root);

    cout << "Postorder (Iterative, One Stack): ";
    printVector(postorder);  // Output: 3 2 1

    // Cleanup
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
