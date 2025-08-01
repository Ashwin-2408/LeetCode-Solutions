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
class Solution {
public:
    string tree2str(TreeNode* root) {
        return recurse(root);
       
    }

    string recurse(TreeNode* root){
        if(root==nullptr){
            return "";
        }
        else if(root->left && root->right){
            return to_string(root->val) + "(" +recurse(root->left) +")"  + "(" +recurse(root->right) +")";;

        }
        else if(root->left ==nullptr && root->right == nullptr){
            return  to_string(root->val);
        }
        else if(root->left==nullptr){
            return to_string(root->val) + "()" + "(" +recurse(root->right) +")";
        }
        else{
            return to_string(root->val) + "(" +recurse(root->left) +")";
            
        }
    }
};