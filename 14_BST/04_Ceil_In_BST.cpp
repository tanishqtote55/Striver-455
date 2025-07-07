/*
    Floor and Ceil in a BST
    Given a root of binary search tree and a key(node) value, find the floor and ceil value for that particular key value.

    Floor Value Node: Node with the greatest data lesser than or equal to the key value. 
    Ceil Value Node: Node with the smallest data larger than or equal to the key value.
    If a particular floor or ceil value is not present then output -1.

    Examples:
    Input : root = [8, 4, 12, 2, 6, 10, 14] , key = 11
    Output : [10, 12]
    Explanation :

    Input : root = [8, 4, 12, 2, 6, 10, 14] , key = 15
    Output : [14, -1]
    Explanation :
*/

#include <iostream>
#include <vector>
using namespace std;

// TreeNode structure
struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> floorCeilOfBST(TreeNode* root, int key) {
        int floorVal = -1;
        int ceilVal = -1;
        TreeNode* node = root;

        while (node) {
            if (node->data == key) {
                floorVal = key;
                ceilVal = key;
                break;
            }
            if (key < node->data) {
                // Current node could be ceil, move left
                ceilVal = node->data;
                node = node->left;
            } else {
                // Current node could be floor, move right
                floorVal = node->data;
                node = node->right;
            }
        }

        return {floorVal, ceilVal};
    }
};

// Utility function to insert nodes into BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->data) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

// Inorder print for visual verification
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    vector<int> bstValues = {8, 4, 12, 2, 6, 10, 14};
    TreeNode* root = nullptr;

    for (int val : bstValues) {
        root = insertBST(root, val);
    }

    cout << "Inorder traversal of BST: ";
    printInorder(root);
    cout << endl;

    int key;
    cout << "Enter key to find floor and ceil: ";
    cin >> key;

    Solution sol;
    vector<int> result = sol.floorCeilOfBST(root, key);

    cout << "Floor: " << result[0] << ", Ceil: " << result[1] << endl;

    return 0;
}