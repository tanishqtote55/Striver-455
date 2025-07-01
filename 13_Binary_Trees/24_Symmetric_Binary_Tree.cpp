/*
    101. Symmetric Tree
    Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

    Example 1:
    Input: root = [1,2,2,3,4,4,3]
    Output: true
    
    Example 2:
    Input: root = [1,2,2,null,3,null,3]
    Output: false    

    Constraints:

    The number of nodes in the tree is in the range [1, 1000].
    -100 <= Node.val <= 100
    
    Follow up: Could you solve it both recursively and iteratively?
*/

#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        return (t1->val == t2->val) &&
               isMirror(t1->left, t2->right) &&
               isMirror(t1->right, t2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* t1 = q.front(); q.pop();
            TreeNode* t2 = q.front(); q.pop();

            if (!t1 && !t2) continue;
            if (!t1 || !t2 || t1->val != t2->val) return false;

            // Push left of t1 and right of t2
            q.push(t1->left);
            q.push(t2->right);

            // Push right of t1 and left of t2
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};

int main() {
    // Example 1:
    TreeNode* root = new TreeNode(1,
        new TreeNode(2, new TreeNode(3), new TreeNode(4)),
        new TreeNode(2, new TreeNode(4), new TreeNode(3))
    );

    Solution sol;
    cout << "Recursive: " << (sol.isSymmetric(root) ? "true" : "false") << endl;

    Solution sol2;
    cout << "Iterative: " << (sol2.isSymmetric(root) ? "true" : "false") << endl;

    return 0;
}



// | Approach  | Time | Space      |
// | --------- | ---- | ---------- |
// | Recursive | O(N) | O(H) stack |
// | Iterative | O(N) | O(N) queue |
