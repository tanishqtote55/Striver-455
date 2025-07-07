/*
    105. Construct Binary Tree from Preorder and Inorder Traversal
    Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

    Example 1:
    Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    Output: [3,9,20,null,null,15,7]

    Example 2:
    Input: preorder = [-1], inorder = [-1]
    Output: [-1]
    
    Constraints:

    1 <= preorder.length <= 3000
    inorder.length == preorder.length
    -3000 <= preorder[i], inorder[i] <= 3000
    preorder and inorder consist of unique values.
    Each value of inorder also appears in preorder.
    preorder is guaranteed to be the preorder traversal of the tree.
    inorder is guaranteed to be the inorder traversal of the tree.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to build tree using preorder and inorder
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map to store value -> index from inorder traversal
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }

        // Start recursive build
        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1,
                     inMap);
    }

private:
    // Recursive helper function
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    unordered_map<int, int>& inMap) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int inRoot = inMap[rootVal];
        int leftSize = inRoot - inStart;

        root->left = build(preorder, preStart + 1, preStart + leftSize,
                           inorder, inStart, inRoot - 1, inMap);
        root->right = build(preorder, preStart + leftSize + 1, preEnd,
                            inorder, inRoot + 1, inEnd, inMap);
        return root;
    }
};

// Print tree in inorder to verify correctness
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Utility to print a vector
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// Main function to test the solution
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    cout << "Preorder Vector: ";
    printVector(preorder);

    cout << "Inorder Vector: ";
    printVector(inorder);

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Inorder Traversal of Constructed Tree:\n";
    printInorder(root);
    cout << endl;

    return 0;
}

// Final Time Complexity:
// O(n)
// where n is the number of nodes in the tree (or size of preorder / inorder array).

// Space Complexity:
// Hash map: O(n)

// Recursion stack (in worst case, skewed tree): O(n)