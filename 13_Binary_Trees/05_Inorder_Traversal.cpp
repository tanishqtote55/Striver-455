/*
    94. Binary Tree Inorder Traversal
    Given the root of a binary tree, return the inorder traversal of its nodes' values.

    Example 1:
    Input: root = [1,null,2,3]
    Output: [1,3,2]
    Explanation:

    Example 2:
    Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
    Output: [4,2,6,5,7,1,3,9,8]
    Explanation:

    Example 3:
    Input: root = []
    Output: []

    Example 4:
    Input: root = [1]
    Output: [1]

    Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100  

    Follow up: Recursive solution is trivial, could you do it iteratively?
*/
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
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
private:
    void inorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        inorder(node->left, result);     // Traverse left
        result.push_back(node->val);     // Visit root
        inorder(node->right, result);    // Traverse right
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

    cout << "Recursive Inorder Traversal: ";
    vector<int> recursiveResult = sol.inorderTraversal(root);
    printVector(recursiveResult);
    // Cleanup
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}