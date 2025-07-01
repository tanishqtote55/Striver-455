/*
    Bottom view of BT
    Given root of binary tree, return the bottom view of the binary tree.

    The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom. Return nodes from the leftmost node to the rightmost node. Also if 2 nodes are outside the shadow of the tree and are at the same position then consider the node that appears later in level traversal.

    Examples:
    Input : root = [20, 8, 22, 5, 3, null, 25, null, null, 10 ,14]
    Output : [5, 10, 3, 14, 25]
    Explanation : From left to right the path is as follows :
    First we encounter node with value 5.
    Then we have nodes 8 , 10 but from bottom only 10 will be visible.
    Next we have 20 , 3 but from bottom only 3 will be visible.
    Next we have 14 , 22 but from bottom only 14 will be visible.
    Then we encounter node with value 25.

    Input : root = [20, 8, 22, 5, 3, 4, 25, null, null, 10 ,14]
    Output : [5, 10, 4, 14, 25]
    Explanation : From left to right the path is as follows :
    First we encounter node with value 5.
    Then we have nodes 8 , 10 but from bottom only 10 will be visible.
    Next we have 20 , 3 and 4. The 3 and 4 will be nodes visible from bottom but as the node 4 appears later from left to right , so only node 4 will be considered visible.
    Next we have 14 , 22 but from bottom only 14 will be visible.
    Then we encounter node with value 25.
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : data(val), left(left), right(right) {}
};

class Solution {
public:
    vector<int> bottomView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        map<int, int> bottomNode; // hd -> node->data
        queue<pair<TreeNode*, int>> q; // node, horizontal distance

        q.push(make_pair(root, 0));

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int hd = q.front().second;
            q.pop();

            bottomNode[hd] = node->data;

            if (node->left)
                q.push(make_pair(node->left, hd - 1));
            if (node->right)
                q.push(make_pair(node->right, hd + 1));
        }

        for (auto it : bottomNode)
            result.push_back(it.second);

        return result;
    }
};

int main() {
    /*
         20
        /  \
       8   22
      / \    \
     5   3    25
        / \
       10 14

    Bottom View: 5 10 3 14 25
    */

    TreeNode* root = new TreeNode(20,
                          new TreeNode(8,
                              new TreeNode(5),
                              new TreeNode(3,
                                  new TreeNode(10),
                                  new TreeNode(14))),
                          new TreeNode(22,
                              nullptr,
                              new TreeNode(25)));

    Solution sol;
    vector<int> bottom = sol.bottomView(root);
    cout << "Bottom View: ";
    for (int val : bottom)
        cout << val << " ";
    cout << endl;

    return 0;
}


// Time: O(N) — each node is visited once.
// Space: O(N) — for map and queue.