/*
    173. Binary Search Tree Iterator
    Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

    BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
    boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
    int next() Moves the pointer to the right, then returns the number at the pointer.
    Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

    You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

    Example 1:
    Input
    ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
    [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
    Output
    [null, 3, 7, true, 9, true, 15, true, 20, false]

    Explanation
    BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
    bSTIterator.next();    // return 3
    bSTIterator.next();    // return 7
    bSTIterator.hasNext(); // return True
    bSTIterator.next();    // return 9
    bSTIterator.hasNext(); // return True
    bSTIterator.next();    // return 15
    bSTIterator.hasNext(); // return True
    bSTIterator.next();    // return 20
    bSTIterator.hasNext(); // return False    

    Constraints:

    The number of nodes in the tree is in the range [1, 105].
    0 <= Node.val <= 106
    At most 105 calls will be made to hasNext, and next.
    
    Follow up:

    Could you implement next() and hasNext() to run in average O(1) time and use O(h) memory, where h is the height of the tree?
*/

#include <iostream>
#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* node = st.top(); st.pop();
        if (node->right) {
            pushLeft(node->right);
        }
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};


int main() {
    /*
       Construct the BST:
               7
              / \
             3   15
                /  \
               9    20
    */
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator bSTIterator(root);
    cout << bSTIterator.next() << endl;    // return 3
    cout << bSTIterator.next() << endl;    // return 7
    cout << bSTIterator.hasNext() << endl; // return true
    cout << bSTIterator.next() << endl;    // return 9
    cout << bSTIterator.hasNext() << endl; // return true
    cout << bSTIterator.next() << endl;    // return 15
    cout << bSTIterator.hasNext() << endl; // return true
    cout << bSTIterator.next() << endl;    // return 20
    cout << bSTIterator.hasNext() << endl; // return false

    return 0;
}

// | Operation   | Time Complexity | Space Complexity |
// | ----------- | --------------- | ---------------- |
// | Constructor | O(h)            | O(h)             |
// | `next()`    | Amortized O(1)  | O(h)             |
// | `hasNext()` | O(1)            | O(1)             |
