#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int findFloor(TreeNode* root, int key) {
        int floorVal = -1;

        while (root) {
            if (root->data == key) {
                return key;
            } else if (key < root->data) {
                root = root->left;
            } else {
                floorVal = root->data;
                root = root->right;
            }
        }

        return floorVal;
    }
};

int main() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    Solution sol;
    int key = 11;
    cout << "Floor of " << key << " is: " << sol.findFloor(root, key) << endl;

    return 0;
}


// Time Complexity:
// O(log N) in balanced BST

// O(N) in worst case (skewed tree)

// Space Complexity:
// O(1) (iterative, no recursion)