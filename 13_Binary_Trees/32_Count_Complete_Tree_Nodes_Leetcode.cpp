/*
    222. Count Complete Tree Nodes
    Given the root of a complete binary tree, return the number of the nodes in the tree.
    According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
    Design an algorithm that runs in less than O(n) time complexity.

    Example 1:
    Input: root = [1,2,3,4,5,6]
    Output: 6

    Example 2:
    Input: root = []
    Output: 0

    Example 3:
    Input: root = [1]
    Output: 1

    Constraints:

    The number of nodes in the tree is in the range [0, 5 * 104].
    0 <= Node.val <= 5 * 104
    The tree is guaranteed to be complete.
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int getLeftHeight(TreeNode* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->left;
        }
        return h;
    }

    int getRightHeight(TreeNode* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->right;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);

        if (leftHeight == rightHeight) {
            return pow(2, leftHeight) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// Helper to build tree from level order input
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front(); q.pop();

        if (i < nodes.size() && nodes[i] != "null") {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main() {
    vector<string> treeInput = {"1", "2", "3", "4", "5", "6"}; // Example 1
    TreeNode* root = buildTree(treeInput);

    Solution sol;
    int count = sol.countNodes(root);

    cout << "Number of nodes in complete binary tree: " << count << endl;

    return 0;
}

// Time & Space Complexity:
// Time: O(log² N) – because for each node we compute height in O(log N), and go log N levels deep.
// Space: O(log N) for recursion stack.

