#include <iostream>
#include <algorithm>
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
    int maxDepth(TreeNode* root) {

        // Base case
        if (root == nullptr)
            return 0;

        // Find depth of left subtree
        int leftDepth = maxDepth(root->left);

        // Find depth of right subtree
        int rightDepth = maxDepth(root->right);

        // Current node contributes 1 level
        return 1 + max(leftDepth, rightDepth);
    }
};

int main() {

    // Creating tree:
    //       3
    //      / \
    //     9  20
    //       /  \
    //      15   7

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    cout << "Maximum Depth = "
         << obj.maxDepth(root) << endl;

    return 0;
}