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
    int bottom_value=0;
    int curr_level=-1;
    int findBottomLeftValue(TreeNode* root) {
        helper(root,0);
        return bottom_value;

        
    }
    void helper(TreeNode* root,int level){
        if(!root){
            return ;
        }
        if(level>curr_level){
            bottom_value=root->val;
            curr_level=level;
            
        }
        helper(root->left,level+1);
        helper(root->right,level+1);

    }
};