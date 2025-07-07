/*
    297. Serialize and Deserialize Binary Tree

    Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

    Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

    Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

    Example 1:
    Input: root = [1,2,3,null,null,4,5]
    Output: [1,2,3,null,null,4,5]
   
    Example 2:
    Input: root = []
    Output: []
    
    Constraints:

    The number of nodes in the tree is in the range [0, 104].
    -1000 <= Node.val <= 1000
*/

#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// Definition for binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Serialize the binary tree using level-order traversal
    string serialize(TreeNode* root) {
        if (!root) return "";

        queue<TreeNode*> q;
        q.push(root);
        string result;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr) {
                result += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            } else {
                result += "null,";
            }
        }

        // Remove trailing comma
        if (!result.empty()) result.pop_back();
        return result;
    }

    // Deserialize the string back into binary tree
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string token;
        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* parent = q.front();
            q.pop();

            // Left child
            if (getline(ss, token, ',')) {
                if (token != "null") {
                    TreeNode* leftNode = new TreeNode(stoi(token));
                    parent->left = leftNode;
                    q.push(leftNode);
                }
            }

            // Right child
            if (getline(ss, token, ',')) {
                if (token != "null") {
                    TreeNode* rightNode = new TreeNode(stoi(token));
                    parent->right = rightNode;
                    q.push(rightNode);
                }
            }
        }

        return root;
    }
};

// Inorder print for verification
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Main function to test serialization and deserialization
int main() {
    Codec ser, deser;

    // Manually build tree: [1, 2, 3, null, null, 4, 5]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string serialized = ser.serialize(root);
    cout << "Serialized Tree: " << serialized << endl;

    TreeNode* deserialized = deser.deserialize(serialized);
    cout << "Inorder of Deserialized Tree: ";
    printInorder(deserialized);
    cout << endl;

    return 0;
}


// Time: O(n)

// Space: O(n)
// For the queue and string building.