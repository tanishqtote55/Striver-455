/*
    701. Insert into a Binary Search Tree
    You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
    Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

    Example 1:
    Input: root = [4,2,7,1,3], val = 5
    Output: [4,2,7,1,3,5]
    Explanation: Another accepted tree is:

    Example 2:
    Input: root = [40,20,60,10,30,50,70], val = 25
    Output: [40,20,60,10,30,50,70,null,null,25]
    
    Example 3:
    Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
    Output: [4,2,7,1,3,5]
    
    Constraints:

    The number of nodes in the tree will be in the range [0, 104].
    -108 <= Node.val <= 108
    All the values Node.val are unique.
    -108 <= val <= 108
    It's guaranteed that val does not exist in the original BST.
*/
#include <iostream>
#include <vector>
using namespace std;

// TreeNode structure definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class with insert function
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        TreeNode* curr = root;
        while(true) {
            if(curr -> val <= val) {
                if(curr -> right != NULL) curr = curr -> right;
                else{
                    curr -> right = new TreeNode(val);
                    break;
                }
            } else {
                if(curr -> left != NULL) curr = curr -> left;
                else{
                    curr -> left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};

// In-order traversal to print the BST (for verification)
void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Helper to build a basic BST from vector (for testing)
TreeNode* buildBSTFromVector(vector<int>& values) {
    Solution sol;
    TreeNode* root = nullptr;
    for (int val : values) {
        root = sol.insertIntoBST(root, val);
    }
    return root;
}

int main() {
    vector<int> initialValues = {4, 2, 7, 1, 3}; // initial tree
    int newVal = 5;

    // Build initial BST
    TreeNode* root = buildBSTFromVector(initialValues);

    // Print original BST in-order
    cout << "Original BST (In-order): ";
    inorderTraversal(root);
    cout << endl;

    // Insert new value
    Solution sol;
    root = sol.insertIntoBST(root, newVal);

    // Print BST after insertion
    cout << "BST after inserting " << newVal << " (In-order): ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

// Time Complexity: O(H), where H = height of the BST
// O(log N) for balanced tree
// O(N) in worst case (skewed tree)
// Space Complexity: O(H) recursion stack (or O(1) if iterative)

