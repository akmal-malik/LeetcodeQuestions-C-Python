#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    public:
    int maxDepth(TreeNode* root) {

        if(root == NULL)
        return 0;

        int leftDepth = maxDepth(root -> left);
        int rightDepth = maxDepth(root -> right);

        return 1 + max(leftDepth, rightDepth);
    }
};

int main () {
    TreeNode* root = new TreeNode(3);
    root -> left = new TreeNode(9);
    root -> right = new TreeNode(20);
    root -> right -> left = new TreeNode(23);
    root -> right -> right = new TreeNode(9);
    root -> right -> right -> left = new TreeNode(16);
    root -> right -> right -> right = new TreeNode(7);

    Solution obj;
    cout << "Maximum Depth = " << obj.maxDepth(root) << endl;

    return 0;
}