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

    TreeNode* invertTree(TreeNode* root) {

        if (root == NULL)
            return NULL;

        TreeNode* temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;

        invertTree(root -> left);
        invertTree(root -> right);

        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(7);
    root -> left -> left = new TreeNode(1);
    root -> left -> right = new TreeNode(3);
    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(9);

    Solution obj;
    obj.invertTree(root);

    cout << "Tree inverted successfully!" << endl;

    return 0;
}