/*
    Requirements needed to construct a unique BT
    Given a pair of tree traversal, return true if a unique binary tree can be constructed otherwise false. Each traversal is represented with integer: 1 -> Preorder , 2 -> Inorder , 3 -> Postorder.

    Examples:
    Input : 1 2
    Output : true 
    Explanation : Answer is True.
    It is possible to construct a unique binary tree. This is because the preorder traversal provides the root of the tree, and the inorder traversal helps determine the left and right subtrees.

    Input : 2 2
    Output : false
    Explanation : Two inorder traversals are insufficient to uniquely determine a binary tree.
*/
#include <iostream>
using namespace std;

class Solution {
public:
    bool uniqueBinaryTree(int a, int b) {
        // valid unique combinations: (Preorder + Inorder) or (Inorder + Postorder)
        if ((a == 1 && b == 2) || (a == 2 && b == 1)) return true;
        if ((a == 2 && b == 3) || (a == 3 && b == 2)) return true;
        return false;
    }
};

int main() {
    Solution sol;

    int a, b;
    cout << "Enter two traversal types (1=Preorder, 2=Inorder, 3=Postorder): ";
    cin >> a >> b;

    if (sol.uniqueBinaryTree(a, b)) {
        cout << "Output: true (A unique binary tree can be constructed)" << endl;
    } else {
        cout << "Output: false (A unique binary tree cannot be constructed)" << endl;
    }

    return 0;
}