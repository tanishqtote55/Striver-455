/*
    199. Binary Tree Right Side View
    Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

    Example 1:
    Input: root = [1,2,3,null,5,null,4]
    Output: [1,3,4]
    Explanation:

    Example 2:
    Input: root = [1,2,3,4,null,null,null,5]
    Output: [1,3,4,5]
    Explanation:

    Example 3:
    Input: root = [1,null,3]
    Output: [1,3]

    Example 4:
    Input: root = []
    Output: []

    Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution class
class Solution {
public:

    void dfs(TreeNode* node, int level, vector<int>& result) {
        if (!node) return;
        
        // If this is the first node at this level
        if (level == result.size()) {
            result.push_back(node->val);
        }
        
        // Recur right first, then left
        dfs(node->right, level + 1, result);
        dfs(node->left, level + 1, result);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            TreeNode* node = nullptr;

            for (int i = 0; i < levelSize; i++) {
                node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Last node at this level is visible from the right
            result.push_back(node->val);
        }

        return result;
    }
};

// Driver code for testing
int main() {
    /*
         1
        / \
       2   3
        \   \
         5   4

    Right View: 1 3 4
    */

    TreeNode* root = new TreeNode(1,
                          new TreeNode(2, nullptr, new TreeNode(5)),
                          new TreeNode(3, nullptr, new TreeNode(4)));

    Solution sol;
    vector<int> view = sol.rightSideView(root);

    cout << "Right Side View: ";
    for (int val : view)
        cout << val << " ";
    cout << endl;

    return 0;
}

// | Complexity Type | Value           |
// | --------------- | --------------- |
// | Time            | `O(N)`          |
// | Space           | `O(W)` ≤ `O(N)` |
