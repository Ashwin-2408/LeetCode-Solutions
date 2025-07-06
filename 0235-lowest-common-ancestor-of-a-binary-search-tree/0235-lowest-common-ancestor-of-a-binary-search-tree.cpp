/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ancestors1,ancestors2;
        find_ancestors(root,p,ancestors1);
        find_ancestors(root,q,ancestors2);
        int i=0;
        TreeNode* ans=root;
        while(i<ancestors1.size() && i < ancestors2.size()){
            if(ancestors1[i]==ancestors2[i]){
                ans=ancestors1[i];
            }
            i++;
        }
        return ans;

        
        
    }
    bool find_ancestors(TreeNode* root,TreeNode* target,vector<TreeNode*>&ancestors){
        if(root==nullptr){
            return false;
        }
        ancestors.push_back(root);
        if(root==target){
            
            return true ;
        }
       
        
        if( find_ancestors(root->left,target,ancestors) ||find_ancestors(root->right,target,ancestors)){
            return true;
        }
        ancestors.pop_back();
        return false;
        
        
        
    }
};