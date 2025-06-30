/*
    102. Binary Tree Level Order Traversal
    Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

    Example 1:

    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[9,20],[15,7]]
    Example 2:

    Input: root = [1]
    Output: [[1]]
    Example 3:

    Input: root = []
    Output: []

    Constraints:

    The number of nodes in the tree is in the range [0, 2000].
    -1000 <= Node.val <= 1000
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
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(currentLevel);
        }

        return result;
    }
};

// Helper to print a 2D vector
void print2DVector(const vector<vector<int>>& vec) {
    for (const auto& level : vec) {
        cout << "[ ";
        for (int val : level) {
            cout << val << " ";
        }
        cout << "]\n";
    }
}

// Main function to test the solution
int main() {
    /*
        Input tree: [3,9,20,null,null,15,7]
        
            3
           / \
          9  20
             / \
            15  7
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> levelOrderResult = sol.levelOrder(root);

    cout << "Level Order Traversal:\n";
    print2DVector(levelOrderResult);

    // Clean up
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}