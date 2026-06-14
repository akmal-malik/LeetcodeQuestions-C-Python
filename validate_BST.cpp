#include <iostream>
#include <climits>
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

bool isValid(TreeNode* root, long long minVal, long long maxVal) {

    if (root == nullptr) {
        return true;
    }

    if (root->val <= minVal || root->val >= maxVal) {
        return false;
    }

    return isValid(root->left, minVal, root->val) &&
           isValid(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValid(root, LLONG_MIN, LLONG_MAX);
}

int main() {

    // Example 1
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    if (isValidBST(root)) {
        cout << "Valid BST" << endl;
    }
    else {
        cout << "Not a Valid BST" << endl;
    }

    return 0;
}