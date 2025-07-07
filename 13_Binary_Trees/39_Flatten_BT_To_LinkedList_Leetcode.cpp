/*
    114. Flatten Binary Tree to Linked List
    Given the root of a binary tree, flatten the tree into a "linked list":

    The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
    The "linked list" should be in the same order as a pre-order traversal of the binary tree.

    Example 1:
    Input: root = [1,2,5,3,4,null,6]
    Output: [1,null,2,null,3,null,4,null,5,null,6]
    
    Example 2:
    Input: root = []
    Output: []
    
    Example 3:
    Input: root = [0]
    Output: [0]
    
    Constraints:

    The number of nodes in the tree is in the range [0, 2000].
    -100 <= Node.val <= 100

    Follow up: Can you flatten the tree in-place (with O(1) extra space)?
*/

#include <iostream>
#include <stack>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // ------- Approach 1: Recursive (Reverse Preorder) --------
    // TC: O(n), SC: O(n) - recursive stack space
    TreeNode* prev = nullptr;
    void flattenRecursive(TreeNode* root) {
        if (!root) return;
        flattenRecursive(root->right);
        flattenRecursive(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }

    // ------- Approach 2: Iterative using Stack --------
    // TC: O(n), SC: O(n)
    void flattenIterative(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            if (curr->right) st.push(curr->right);
            if (curr->left) st.push(curr->left);
            if (!st.empty()) curr->right = st.top();
            curr->left = nullptr;
        }
    }

    // ------- Approach 3: Morris Traversal (Optimal) --------
    // TC: O(n), SC: O(1)
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* prev = curr->left;
                while (prev->right) prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};

// Helper to print tree in preorder (before flattening)
void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Helper to print flattened tree (right pointers)
void printFlattened(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;
}

// Helper to create a fresh tree
TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    return root;
}

int main() {
    Solution sol;

    // Test Recursive
    TreeNode* tree1 = createTree();
    cout << "Original Tree (Preorder): ";
    printPreorder(tree1);
    cout << "\nFlattened (Recursive): ";
    sol.flattenRecursive(tree1);
    printFlattened(tree1);

    // Reset prev pointer for next test
    sol.prev = nullptr;

    // Test Iterative
    TreeNode* tree2 = createTree();
    cout << "Original Tree (Preorder): ";
    printPreorder(tree2);
    cout << "\nFlattened (Iterative): ";
    sol.flattenIterative(tree2);
    printFlattened(tree2);

    // Test Morris (Optimal)
    TreeNode* tree3 = createTree();
    cout << "Original Tree (Preorder): ";
    printPreorder(tree3);
    cout << "\nFlattened (Morris): ";
    sol.flatten(tree3);
    printFlattened(tree3);

    return 0;
}
