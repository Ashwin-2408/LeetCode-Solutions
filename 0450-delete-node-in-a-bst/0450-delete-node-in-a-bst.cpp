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
    TreeNode* find_right_minimum(TreeNode* root){
        while(root->left){
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }
        TreeNode* curr = root;

        if (curr->val < key) {
            
            curr->right = deleteNode(curr->right, key);

        } else if (curr->val > key) {
            curr->left = deleteNode(curr->left, key);
            
        } else {
            TreeNode* temp=curr->left;
            TreeNode* right=find_right_minimum(curr->right);
           
            right->left=temp;
            

            return curr->right;
        }

        return root;
    }
};