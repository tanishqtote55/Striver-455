/*
    Minimum time taken to burn the BT from a given Node
    Given a target node data and a root of binary tree. If the target is set on fire, determine the shortest amount of time needed to burn the entire binary tree.

    It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.

    Examples:
    Input : root = [1, 2, 3, 4, null, 5, 6, null, 7]. target = 1
    Output : 3
    Explanation : The node with value 1 is set on fire.
    In 1st second it burns node 2 and node 3.
    In 2nd second it burns nodes 4, 5, 6.
    In 3rd second it burns node 7.

    Input : root = [1, 2, 3, null, 5, null, 4], target = 4
    Output : 4
    Explanation : The node with value 4 is set on fire.
    In 1st second it burns node 3.
    In 2nd second it burns node 1.
    In 3rd second it burns node 2.
    In 4th second it burns node 5.
*/


#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Step 1: Build parent map and locate the target node
    TreeNode* markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentTrack, int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* target = nullptr;

        while (!q.empty()) {
            TreeNode* current = q.front(); q.pop();

            if (current->data == start) target = current;

            if (current->left) {
                parentTrack[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parentTrack[current->right] = current;
                q.push(current->right);
            }
        }
        return target;
    }

    // Step 2: BFS to simulate fire spread
    int timeToBurnTree(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parentTrack;
        TreeNode* target = markParents(root, parentTrack, start);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool anySpread = false;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();

                if (node->left && visited.find(node->left) == visited.end()) {
                    anySpread = true;
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    anySpread = true;
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if (parentTrack.count(node) && visited.find(parentTrack[node]) == visited.end()) {
                    anySpread = true;
                    visited.insert(parentTrack[node]);
                    q.push(parentTrack[node]);
                }
            }

            if (anySpread) time++;
        }

        return time;
    }
};

// Helper: Build tree from level-order input
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

// Main function
int main() {
    // Example 1:
    vector<string> treeInput = {"1", "2", "3", "null", "5", "null", "4"};
    int target = 4;

    TreeNode* root = buildTree(treeInput);
    Solution sol;

    int time = sol.timeToBurnTree(root, target);
    cout << "Minimum time to burn the tree from node " << target << " is: " << time << endl;

    return 0;
}

// | Metric           | Value  |
// | ---------------- | ------ |
// | Time Complexity  | `O(N)` |
// | Space Complexity | `O(N)` |
