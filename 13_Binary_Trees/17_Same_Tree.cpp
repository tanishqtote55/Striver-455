/*
    100. Same Tree
    Given the roots of two binary trees p and q, write a function to check if they are the same or not.

    Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

    Example 1:
    Input: p = [1,2,3], q = [1,2,3]
    Output: true

    Example 2:
    Input: p = [1,2], q = [1,null,2]
    Output: false

    Example 3:
    Input: p = [1,2,1], q = [1,1,2]
    Output: false
    
    Constraints:

    The number of nodes in both trees is in the range [0, 100].
    -104 <= Node.val <= 104
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: both null
        if (!p && !q) return true;

        // One null, one not
        if (!p || !q) return false;

        // Values don't match
        if (p->val != q->val) return false;

        // Check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Optional test
int main() {
    TreeNode* p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q = new TreeNode(1, new TreeNode(2), new TreeNode(3));

    Solution sol;
    cout << (sol.isSameTree(p, q) ? "Trees are same" : "Trees are not same") << endl;

    return 0;
}

// Time: O(n) — compare each node once.
// Space: O(h) — recursion stack (h = height of tree).