#include <iostream>
#include <queue>
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

        if (root == NULL)
            return 0;

        queue<TreeNode*> q;
        q.push(root);

        int depth = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                TreeNode* node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            depth++;
        }

        return depth;
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