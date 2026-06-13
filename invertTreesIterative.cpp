#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:

    /**
     * Function: invertTree
     * --------------------
     * Inverts a binary tree using recursion (DFS).
     *
     * Approach:
     * 1. Swap left and right child of current node.
     * 2. Recursively invert left subtree.
     * 3. Recursively invert right subtree.
     *
     * Time Complexity: O(n)
     *      - Every node is visited once.
     *
     * Space Complexity: O(h)
     *      - Recursive call stack.
     *      - Worst case: O(n)
     *      - Balanced tree: O(log n)
     *
     * @param root Pointer to root node.
     * @return Root of inverted tree.
     */
    TreeNode* invertTree(TreeNode* root) {

        // Base case
        if (root == nullptr)
            return nullptr;

        // Swap children
        swap(root->left, root->right);

        // Invert left subtree
        invertTree(root->left);

        // Invert right subtree
        invertTree(root->right);

        return root;
    }
};

int main() {

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution obj;
    obj.invertTree(root);

    cout << "Tree inverted successfully!" << endl;

    return 0;
}