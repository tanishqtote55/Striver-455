/*
    863. All Nodes Distance K in Binary Tree
    Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
    You can return the answer in any order.

    Example 1:
    Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
    Output: [7,4,1]
    Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

    Example 2:
    Input: root = [1], target = 1, k = 3
    Output: []
    
    Constraints:

    The number of nodes in the tree is in the range [1, 500].
    0 <= Node.val <= 500
    All the values Node.val are unique.
    target is the value of one of the nodes in the tree.
    0 <= k <= 1000
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            if (node->left) {
                parentMap[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        markParents(root, parentMap);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int currentLevel = 0;

        while (!q.empty()) {
            int size = q.size();
            if (currentLevel == k) break;
            currentLevel++;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();

                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                }

                if (parentMap.count(node) && visited.find(parentMap[node]) == visited.end()) {
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                }
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};

// Builds a binary tree from level-order vector input
TreeNode* buildTree(const vector<string>& nodes, unordered_map<int, TreeNode*>& valToNode) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    valToNode[root->val] = root;

    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front(); q.pop();

        if (i < nodes.size() && nodes[i] != "null") {
            TreeNode* left = new TreeNode(stoi(nodes[i]));
            curr->left = left;
            q.push(left);
            valToNode[left->val] = left;
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            TreeNode* right = new TreeNode(stoi(nodes[i]));
            curr->right = right;
            q.push(right);
            valToNode[right->val] = right;
        }
        i++;
    }

    return root;
}

int main() {
    // Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
    vector<string> treeInput = {"3", "5", "1", "6", "2", "0", "8", "null", "null", "7", "4"};
    int targetVal = 5;
    int k = 2;

    unordered_map<int, TreeNode*> valToNode;
    TreeNode* root = buildTree(treeInput, valToNode);
    TreeNode* target = valToNode[targetVal];

    Solution sol;
    vector<int> result = sol.distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from node " << targetVal << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// | Metric                      | Value  |
// | --------------------------- | ------ |
// | Time Complexity             | `O(N)` |
// | Space Complexity            | `O(N)` |
// | Where `N = number of nodes` |        |
