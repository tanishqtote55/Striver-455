#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Tree node definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Traversal function
void allTraversals(TreeNode* root, vector<int>& preorder, vector<int>& inorder, vector<int>& postorder) {
    if (!root) return;

    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto& [node, state] = st.top();

        if (state == 1) {
            preorder.push_back(node->val);  // Preorder: first visit
            state++;
            if (node->left)
                st.push({node->left, 1});
        }
        else if (state == 2) {
            inorder.push_back(node->val);   // Inorder: after left
            state++;
            if (node->right)
                st.push({node->right, 1});
        }
        else {
            postorder.push_back(node->val); // Postorder: after right
            st.pop();
        }
    }
}

// Print helper
void print(const string& label, const vector<int>& vec) {
    cout << label << ": ";
    for (int x : vec) cout << x << " ";
    cout << endl;
}

// Main
int main() {
    /*
         Tree:
             1
            / \
           2   3
          / \
         4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> preorder, inorder, postorder;
    allTraversals(root, preorder, inorder, postorder);

    print("Preorder", preorder);     // Expected: 1 2 4 5 3
    print("Inorder", inorder);       // Expected: 4 2 5 1 3
    print("Postorder", postorder);   // Expected: 4 5 2 3 1

    // Cleanup
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
