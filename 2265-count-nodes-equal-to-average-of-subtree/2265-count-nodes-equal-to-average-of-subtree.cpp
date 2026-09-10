/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> solve(TreeNode* root, int& result) {
        if (!root) {
            return {0, 0};
        }

        auto p1 = solve(root->left, result);
        auto p2 = solve(root->right, result);

        int totalSum = p1.first + p2.first + root->val;
        int totalNodes = p1.second + p2.second + 1;

        int avg = totalSum / totalNodes;
        if (avg == root->val) {
            result += 1;
        }

        return {totalSum, totalNodes};
    }

    int averageOfSubtree(TreeNode* root) {
        int result = 0;
        solve(root, result);
        return result;
    }
};