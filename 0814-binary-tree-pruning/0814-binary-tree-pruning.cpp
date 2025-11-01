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
    TreeNode* pruneTree(TreeNode* root) {
        contain_one(root);
        if(root->left==nullptr && root->right==nullptr && root->val==0){
            return nullptr;
        }
        return root;
    }
    bool contain_one(TreeNode* root) {
        if (root == nullptr) {
            return false;
        }
        if (root->val == 1) {
            if (!contain_one(root->left)) {
                root->left = nullptr;
            }
            if (!contain_one(root->right)) {
                root->right = nullptr;
            }
            return true;
        }
        if (root->val == 0) {
            if (!contain_one(root->left)) {
                root->left = nullptr;
            }
            if (!contain_one(root->right)) {
                root->right = nullptr;
            }
            return contain_one(root->left) || contain_one(root->right);
        }
        return false;
    }
}

;