/*
    653. Two Sum IV - Input is a BST
    Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

    Example 1:
    Input: root = [5,3,6,2,4,null,7], k = 9
    Output: true

    Example 2:
    Input: root = [5,3,6,2,4,null,7], k = 28
    Output: false

    Constraints:

    The number of nodes in the tree is in the range [1, 104].
    -104 <= Node.val <= 104
    root is guaranteed to be a valid binary search tree.
    -105 <= k <= 105
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// BST Iterator class
class BSTIterator {
    stack<TreeNode*> st;
    bool reverse; // false = inorder (left -> right), true = reverse inorder (right -> left)

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    int next() {
        TreeNode* node = st.top(); st.pop();
        if (!reverse) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }

private:
    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            node = reverse ? node->right : node->left;
        }
    }
};

// Main solution
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator left(root, false);  // In-order
        BSTIterator right(root, true);  // Reverse in-order

        int i = left.next();
        int j = right.next();

        while (i < j) {
            int sum = i + j;
            if (sum == k) return true;
            else if (sum < k) {
                if (left.hasNext())
                    i = left.next();
                else
                    break;
            } else {
                if (right.hasNext())
                    j = right.next();
                else
                    break;
            }
        }

        return false;
    }
};

// Helper to insert into BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int main() {
    /*
        Construct BST from [5,3,6,2,4,null,7]

                  5
                 / \
                3   6
               / \    \
              2   4    7
    */
    vector<int> vals = {5, 3, 6, 2, 4, 7};
    TreeNode* root = nullptr;
    for (int val : vals)
        root = insert(root, val);

    Solution sol;

    // Test 1
    int k1 = 9;
    cout << "findTarget(root, " << k1 << "): " << (sol.findTarget(root, k1) ? "true" : "false") << endl;

    // Test 2
    int k2 = 28;
    cout << "findTarget(root, " << k2 << "): " << (sol.findTarget(root, k2) ? "true" : "false") << endl;

    return 0;
}

// | Metric | Complexity                                           |
// | ------ | ---------------------------------------------------- |
// | Time   | O(n) worst-case (balanced → O(log n) avg.)           |
// | Space  | O(h) per iterator = O(h) total (`h = height of BST`) |
