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

    /**
     * Function: invertTree
     * --------------------
     * Inverts a binary tree using
     * Breadth First Search (Level Order Traversal).
     *
     * Approach:
     * 1. Store root in queue.
     * 2. Process each node level by level.
     * 3. Swap left and right child.
     * 4. Add children to queue.
     *
     * Time Complexity: O(n)
     *      - Every node visited once.
     *
     * Space Complexity: O(w)
     *      - w = maximum width of tree.
     *      - Worst case: O(n)
     *
     * @param root Pointer to root node.
     * @return Root of inverted tree.
     */
    TreeNode* invertTree(TreeNode* root) {

        // Empty tree
        if (root == nullptr)
            return nullptr;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* curr = q.front();
            q.pop();

            // Swap children
            swap(curr->left, curr->right);

            // Add left child
            if (curr->left)
                q.push(curr->left);

            // Add right child
            if (curr->right)
                q.push(curr->right);
        }

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