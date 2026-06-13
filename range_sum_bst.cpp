#include <iostream>
using namespace std;

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }

        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }

        if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }

        return root->val +
               rangeSumBST(root->left, low, high) +
               rangeSumBST(root->right, low, high);
    }
};

int main() {
    /*
            10
           /  \
          5    15
         / \     \
        3   7     18
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    root->right->right = new TreeNode(18);

    int low = 7;
    int high = 15;

    Solution obj;

    cout << "Sum in range = "
         << obj.rangeSumBST(root, low, high)
         << endl;

    return 0;
}