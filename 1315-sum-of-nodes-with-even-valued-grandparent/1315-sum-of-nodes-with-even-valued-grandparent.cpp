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
    int sumEvenGrandparent(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int value = 0;
        if (root->val % 2 == 0) {
            if (root->left) {
                if (root->left->left) {
                    value+=root->left->left->val;
                }
                if (root->left->right) {
                    value+=root->left->right->val;
                }
            }
            if (root->right) {
                if (root->right->left) {
                    value+=root->right->left->val;
                }
                if (root->right->right) {
                    value+=root->right->right->val;
                }
            }
        }
        return value + sumEvenGrandparent(root->left) +
               sumEvenGrandparent(root->right);
    }
};