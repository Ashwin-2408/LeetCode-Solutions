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
        vector<TreeNode*> pnodes,qnodes;
        lca(root,p,pnodes);
        lca(root,q,qnodes);
        int i=0;
        TreeNode* ancestor=nullptr;
        while(i<pnodes.size() && i<qnodes.size()){
            if(pnodes[i]==qnodes[i]){
                ancestor=pnodes[i];
            }
            else{
                break;
            }
            i++;
        }
        return ancestor;

        
    }
    bool lca(TreeNode* root,TreeNode*p,vector<TreeNode*>& nodes){
        if(root==nullptr){
            return false;
        }
        nodes.push_back(root);
        if(root==p){
            return true;
        }
        
        if(lca(root->left,p,nodes) || lca(root->right,p,nodes)){
            return true;
        }
        nodes.pop_back();
        return false;


    }
};