/*
    662. Maximum Width of Binary Tree
    Given the root of a binary tree, return the maximum width of the given tree.
    The maximum width of a tree is the maximum width among all levels.
    The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
    It is guaranteed that the answer will in the range of a 32-bit signed integer.

    Example 1:
    Input: root = [1,3,2,5,3,null,9]
    Output: 4
    Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
  
    Example 2:
    Input: root = [1,3,2,5,null,null,9,6,null,7]
    Output: 7
    Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

    Example 3:
    Input: root = [1,3,2,5]
    Output: 2
    Explanation: The maximum width exists in the second level with length 2 (3,2).
    
    Constraints:

    The number of nodes in the tree is in the range [1, 3000].
    -100 <= Node.val <= 100
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;

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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        // queue stores: node and its index in a complete binary tree
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            unsigned long long minIndex = q.front().second;
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front().first;
                unsigned long long index = q.front().second;
                q.pop();
                index -= minIndex;

                if (i == 0) first = index;
                if (i == size - 1) last = index;

                if (node->left)
                    q.push(make_pair(node->left, 2 * index));
                if (node->right)
                    q.push(make_pair(node->right, 2 * index + 1));
            }

            maxWidth = max(maxWidth, (int)(last - first + 1));
        }

        return maxWidth;
    }
};

// Helper to build tree from level-order input
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

int main() {
    // Test Case 1: root = [1,3,2,5,3,null,9]
    vector<string> treeInput = {"1", "3", "2", "5", "3", "null", "9"};
    TreeNode* root = buildTree(treeInput);

    Solution sol;
    int result = sol.widthOfBinaryTree(root);

    cout << "Maximum Width of Binary Tree: " << result << endl;

    return 0;
}

// | Metric              | Value                              |
// | ------------------- | ---------------------------------- |
// | ⏱ Time Complexity   | `O(N)` — visit each node once      |
// | 📦 Space Complexity | `O(N)` — queue space in worst case |
