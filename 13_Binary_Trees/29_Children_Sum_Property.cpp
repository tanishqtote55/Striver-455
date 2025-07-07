/*
    Children Sum Property in Binary Tree
    Given the root of a binary tree, return true if and only if every node’s value is equal to the sum of the values stored in its left and right children.
    For any missing ( null ) child, its value is treated as 0.
    A leaf node automatically satisfies the rule because both children are null.

    Examples:
    Input: root = [1,4,3,5]
    Output: false
    Explanation:
    The root is 1, but its children sum to 4 + 3 = 7. Since 1 ≠ 7, the tree violates the property.

    Input: root = [10,4,6,1,3,2,4]
    Output: true
    Explanation:
    4 = 1 + 3
    6 = 2 + 4
    10 = 4 + 6
    All internal nodes satisfy the condition.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function 1: Check if tree satisfies children sum property
    bool checkChildrenSum(TreeNode* root) {
        if (!root || (!root->left && !root->right))
            return true;

        int leftVal = root->left ? root->left->val : 0;
        int rightVal = root->right ? root->right->val : 0;

        bool currValid = (root->val == leftVal + rightVal);

        return currValid &&
               checkChildrenSum(root->left) &&
               checkChildrenSum(root->right);
    }

    // Function 2: Modify the tree to satisfy children sum property
    void changeTree(TreeNode* root) {
        if (root == NULL) return;

        int child = 0;
        if (root->left) child += root->left->val;
        if (root->right) child += root->right->val;

        if (child >= root->val) {
            root->val = child;
        } else {
            if (root->left)
                root->left->val = root->val;
            else if (root->right)
                root->right->val = root->val;
        }

        changeTree(root->left);
        changeTree(root->right);

        int tot = 0;
        if (root->left) tot += root->left->val;
        if (root->right) tot += root->right->val;

        if (root->left || root->right) {
            root->val = tot;
        }
    }
};

// Helper to build tree from level-order vector<string> input
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "null") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main() {
    // Example input: [10,4,6,1,3,2,4]
    vector<string> treeInput = {"10", "4", "6", "1", "3", "2", "4"};
    TreeNode* root = buildTree(treeInput);

    Solution sol;

    cout << "Before changeTree:\n";
    cout << "Children Sum Property holds: " << (sol.checkChildrenSum(root) ? "true" : "false") << endl;

    sol.changeTree(root);

    cout << "After changeTree:\n";
    cout << "Children Sum Property holds: " << (sol.checkChildrenSum(root) ? "true" : "false") << endl;

    return 0;
}

// | Metric           | Value                    |
// | ---------------- | ------------------------ |
// | Time Complexity  | `O(N)`                   |
// | Space Complexity | `O(H)` (recursive stack) |
