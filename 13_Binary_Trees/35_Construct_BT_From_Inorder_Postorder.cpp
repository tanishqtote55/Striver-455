/*
    106. Construct Binary Tree from Inorder and Postorder Traversal
    Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

    Example 1:
    Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
    Output: [3,9,20,null,null,15,7]
    
    Example 2:
    Input: inorder = [-1], postorder = [-1]
    Output: [-1]

    Constraints:

    1 <= inorder.length <= 3000
    postorder.length == inorder.length
    -3000 <= inorder[i], postorder[i] <= 3000
    inorder and postorder consist of unique values.
    Each value of postorder also appears in inorder.
    inorder is guaranteed to be the inorder traversal of the tree.
    postorder is guaranteed to be the postorder traversal of the tree.
*/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;

        // Create a hashmap for inorder index lookup
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }

        int postIndex = postorder.size() - 1;

        return build(inorder, postorder, inMap, 0, inorder.size() - 1, postIndex);
    }

private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    unordered_map<int, int>& inMap,
                    int inStart, int inEnd, int& postIndex) {
        
        if (inStart > inEnd) return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inRoot = inMap[rootVal];

        // Build right first (reverse of postorder)
        root->right = build(inorder, postorder, inMap, inRoot + 1, inEnd, postIndex);
        root->left = build(inorder, postorder, inMap, inStart, inRoot - 1, postIndex);

        return root;
    }
};

// Utility function to print inorder traversal of the tree
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Main function for testing
int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);

    cout << "Inorder of Constructed Tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}

// Time Complexity: O(n)
// Each node is processed once and map lookup is O(1).

// Space Complexity: O(n)
// Due to:
// The recursion stack (O(n) in worst case),
// The hash map for inorder indexing (O(n)).