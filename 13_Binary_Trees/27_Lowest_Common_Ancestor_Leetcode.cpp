/*
    236. Lowest Common Ancestor of a Binary Tree
    Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

    Example 1:
    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    Output: 3
    Explanation: The LCA of nodes 5 and 1 is 3.
    
    Example 2:
    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
    Output: 5
    Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
    
    Example 3:
    Input: root = [1,2], p = 1, q = 2
    Output: 1
    
    Constraints:

    The number of nodes in the tree is in the range [2, 105].
    -109 <= Node.val <= 109
    All Node.val are unique.
    p != q
    p and q will exist in the tree.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q)
            return root;

        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        if (leftLCA && rightLCA) return root;

        return leftLCA ? leftLCA : rightLCA;
    }
};

// Helper to build tree from level order input
TreeNode* buildTree(const vector<string>& nodes, unordered_map<int, TreeNode*>& valToNode) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    valToNode[root->val] = root;
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "null") {
            current->left = new TreeNode(stoi(nodes[i]));
            valToNode[current->left->val] = current->left;
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            current->right = new TreeNode(stoi(nodes[i]));
            valToNode[current->right->val] = current->right;
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main() {
    // Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    vector<string> nodes = {"3", "5", "1", "6", "2", "0", "8", "null", "null", "7", "4"};

    unordered_map<int, TreeNode*> valToNode;
    TreeNode* root = buildTree(nodes, valToNode);

    int pVal = 5, qVal = 1;

    TreeNode* p = valToNode[pVal];
    TreeNode* q = valToNode[qVal];

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor of " << pVal << " and " << qVal << " is: " << lca->val << endl;

    return 0;
}

// | Metric           | Complexity |
// | ---------------- | ---------- |
// | Time Complexity  | `O(N)`     |
// | Space Complexity | `O(H)`     |
