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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode * new_root= new TreeNode(val);
            new_root->left=root;
            return new_root;
        }
        add_row(root,val,depth,1);
        return root;
        
        
    }
    void add_row(TreeNode* root,int val,int depth,int level){
        if(root==nullptr){
            return;
        }
        if(level==depth-1){
            TreeNode* temp_left=root->left;
            TreeNode* temp_right=root->right;

            root->right=new TreeNode(val);
            root->right->right=temp_right;
            root->left=new TreeNode(val);
            root->left->left=temp_left;
            return;

        }
        else{
            add_row(root->left,val,depth,level+1);
            add_row(root->right,val,depth,level+1);
        }

    }
};