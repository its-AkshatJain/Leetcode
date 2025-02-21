/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
    unordered_set<int> node_values;
    void recoveryBinaryTree(TreeNode* curr, int val){
        if(!curr) return;

        node_values.insert(val);
        recoveryBinaryTree(curr->left, 2*val+1);
        recoveryBinaryTree(curr->right, 2*val+2);
    }
public:
    FindElements(TreeNode* root) {
        node_values.insert(0);
        recoveryBinaryTree(root->left, 1);
        recoveryBinaryTree(root->right, 2);
    }
    
    bool find(int target) {
      return node_values.count(target)>0;  
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */