/*
    Top View of BT
    Given the root of a binary tree, return the top view of the binary tree.

    Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. Return nodes from the leftmost node to the rightmost node. Also if 2 nodes are outside the shadow of the tree and are at the same position then consider the left ones only(i.e. leftmost). 

    Examples:
    Input : root = [1, 2, 3, 4, 5, 6, 7]
    Output : [4, 2, 1, 3, 7]
    Explanation :

    Input : root = [10, 20, 30, 40, 60, 90, 100]
    Output : [40, 20, 10, 30, 100]
    Explanation :
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> topView(TreeNode *root) {
        vector<int> result;
        if (!root) return result;

        map<int, int> topNode;  // horizontal distance -> node value
        queue<pair<TreeNode*, int>> q;  // node and horizontal distance

        q.push({root, 0});

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int hd = front.second;

            // Insert into map if this HD is seen for the first time
            if (topNode.find(hd) == topNode.end()) {
                topNode[hd] = node->data;
            }

            if (node->left) {
                q.push({node->left, hd - 1});
            }
            if (node->right) {
                q.push({node->right, hd + 1});
            }
        }

        // Extract values in order of HD (from leftmost to rightmost)
        for (auto it : topNode) {
            result.push_back(it.second);
        }

        return result;
    }
};

// 🧪 Sample Main
int main() {
    /*
           1
         /   \
        2     3
       / \   / \
      4   5 6   7

      Top View: 4 2 1 3 7
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3, new TreeNode(6), new TreeNode(7));

    Solution sol;
    vector<int> top = sol.topView(root);

    cout << "Top View: ";
    for (int val : top) cout << val << " ";
    cout << endl;

    return 0;
}


// Time: O(N) — each node is visited once.
// Space: O(N) — for map and queue.
