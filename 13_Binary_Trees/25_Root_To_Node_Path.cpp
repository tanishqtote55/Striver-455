/*
    Print root to node path in BT
    Given the root of a binary tree. Return all the root-to-leaf paths in the binary tree.
    A leaf node of a binary tree is the node which does not have a left and right child.

    Examples:
    Input : root = [1, 2, 3, null, 5, null, 4]
    Output : [ [1, 2, 5] , [1, 3, 4] ]
    Explanation : There are only two paths from root to leaf.
    From root 1 to 5 , 1 -> 2 -> 5.
    From root 1 to 4 , 1 -> 3 -> 4.

    Input : root = [1, 2, 3, 4, 5]
    Output : [ [1, 2, 4] , [1, 2, 5] , [1, 3] ]
    Explanation :
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void dfs(TreeNode* node, vector<int>& path, vector<vector<int>>& result) {
        if (!node) return;

        path.push_back(node->data);

        // if leaf node, save the current path
        if (!node->left && !node->right) {
            result.push_back(path);
        }

        dfs(node->left, path, result);
        dfs(node->right, path, result);

        // backtrack
        path.pop_back();
    }

    vector<vector<int>> allRootToLeaf(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, path, result);
        return result;
    }
};

// Helper function to build a binary tree from level order input
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

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

// Function to print all root-to-leaf paths
void printPaths(const vector<vector<int>>& paths) {
    for (const auto& path : paths) {
        cout << "[ ";
        for (int val : path) {
            cout << val << " ";
        }
        cout << "]\n";
    }
}

// Main function
int main() {
    // Example input: root = [1, 2, 3, null, 5, null, 4]
    vector<string> treeInput = {"1", "2", "3", "null", "5", "null", "4"};
    TreeNode* root = buildTree(treeInput);

    Solution sol;
    vector<vector<int>> result = sol.allRootToLeaf(root);

    cout << "Root to Leaf Paths:\n";
    printPaths(result);

    return 0;
}

// | Metric           | Complexity                             |
// | ---------------- | -------------------------------------- |
// | Time Complexity  | `O(N + L * H)` (≈ `O(N^2)` worst case) |
// | Space Complexity | `O(H + L * H)` (≈ `O(N^2)` worst case) |
