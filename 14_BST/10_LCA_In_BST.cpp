/*
    235. Lowest Common Ancestor of a Binary Search Tree
    Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

    Example 1:
    Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
    Output: 6
    Explanation: The LCA of nodes 2 and 8 is 6.
    
    Example 2:
    Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
    Output: 2
    Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
    
    Example 3:
    Input: root = [2,1], p = 2, q = 1
    Output: 2

    Constraints:

    The number of nodes in the tree is in the range [2, 105].
    -109 <= Node.val <= 109
    All Node.val are unique.
    p != q
    p and q will exist in the BST.
*/

#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if (!root) return nullptr;

    //     if (p->val < root->val && q->val < root->val)
    //         return lowestCommonAncestor(root->left, p, q);
    //     else if (p->val > root->val && q->val > root->val)
    //         return lowestCommonAncestor(root->right, p, q);
    //     else
    //         return root;
    // }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            } else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            } else {
                return root;
            }
        }
        return nullptr;
    }
};

// Helper function to insert nodes in BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Helper to find a node by value
TreeNode* find(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    if (val < root->val) return find(root->left, val);
    return find(root->right, val);
}

int main() {
    /*
        Constructing BST:
               6
             /   \
            2     8
           / \   / \
          0   4 7   9
             / \
            3   5
    */

    TreeNode* root = nullptr;
    int values[] = {6, 2, 8, 0, 4, 7, 9, 3, 5};
    for (int val : values)
        root = insert(root, val);

    // Example 1: LCA of 2 and 8 → 6
    TreeNode* p = find(root, 2);
    TreeNode* q = find(root, 8);

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;

    // Example 2: LCA of 2 and 4 → 2
    p = find(root, 2);
    q = find(root, 4);
    lca = sol.lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;

    return 0;
}


// Time: O(h), where h is height of BST (O(log n) if balanced, O(n) worst case).
// Space: O(1) for iterative version (can also be written recursively with O(h) space).