/*
    987. Vertical Order Traversal of a Binary Tree
    Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

    For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

    The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

    Return the vertical order traversal of the binary tree.

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: [[9],[3,15],[20],[7]]
    Explanation:
    Column -1: Only node 9 is in this column.
    Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
    Column 1: Only node 20 is in this column.
    Column 2: Only node 7 is in this column.
    
    Example 2:
    Input: root = [1,2,3,4,5,6,7]
    Output: [[4],[2],[1,5,6],[3],[7]]
    Explanation:
    Column -2: Only node 4 is in this column.
    Column -1: Only node 2 is in this column.
    Column 0: Nodes 1, 5, and 6 are in this column.
            1 is at the top, so it comes first.
            5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
    Column 1: Only node 3 is in this column.
    Column 2: Only node 7 is in this column.
    
    Example 3:
    Input: root = [1,2,3,4,6,5,7]
    Output: [[4],[2],[1,5,6],[3],[7]]
    Explanation:
    This case is the exact same as example 2, but with nodes 5 and 6 swapped.
    Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.

    Constraints:

    The number of nodes in the tree is in the range [1, 1000].
    0 <= Node.val <= 1000
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

// Definition for a binary tree node.
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map<col, Map<row, multiset<node values>>>
        map<int, map<int, multiset<int>>> nodes;
        queue<tuple<TreeNode*, int, int>> q;
        q.push(make_tuple(root, 0, 0));

        while (!q.empty()) {
            tuple<TreeNode*, int, int> temp = q.front();
            q.pop();
            TreeNode* node = get<0>(temp);
            int row = get<1>(temp);
            int col = get<2>(temp);

            nodes[col][row].insert(node->val);

            if (node->left)
                q.push(make_tuple(node->left, row + 1, col - 1));
            if (node->right)
                q.push(make_tuple(node->right, row + 1, col + 1));
        }

        vector<vector<int>> result;
        for (auto it1 = nodes.begin(); it1 != nodes.end(); ++it1) {
            vector<int> colVals;
            for (auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) {
                colVals.insert(colVals.end(), it2->second.begin(), it2->second.end());
            }
            result.push_back(colVals);
        }

        return result;
    }
};

// Sample tree for testing
int main() {
    /*
        Tree:
            1
           / \
          2   3
         / \ / \
        4  5 6  7

        Expected Output: [[4],[2],[1,5,6],[3],[7]]
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3, new TreeNode(6), new TreeNode(7));

    Solution sol;
    vector<vector<int>> output = sol.verticalTraversal(root);

    cout << "Vertical Order Traversal:\n";
    for (const auto& col : output) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time: O(n log n) — due to map and multiset operations.
// Space: O(n) — for storing node positions and final result.