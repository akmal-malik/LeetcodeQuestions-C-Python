#include <iostream>
#include <vector>
#include <queue>

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
    TreeNode* solve(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = solve(nums, left, mid - 1);
        root->right = solve(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};

void levelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        cout << curr->val << " ";

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};

    Solution obj;
    TreeNode* root = obj.sortedArrayToBST(nums);

    cout << "Level Order Traversal: ";
    levelOrder(root);

    return 0;
}