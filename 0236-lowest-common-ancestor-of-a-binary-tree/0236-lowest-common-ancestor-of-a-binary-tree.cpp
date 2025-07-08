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
        vector<TreeNode*> node1,node2;
        find_ancestors(root,p,node1);
        find_ancestors(root,q,node2);
        int i=0;
        TreeNode* ancestor;
        while(i<node1.size() && i<node2.size()){
            if(node1[i]==node2[i]){
                ancestor=node1[i];
            }
            i++;
        }
        return ancestor;

        
    }
    bool find_ancestors(TreeNode* root,TreeNode* target,vector<TreeNode*>& ancestor){
        if(root==nullptr){
            return false;
        }
        ancestor.push_back(root);
        if(root==target){
            return true;

        }
        if(find_ancestors(root->left,target,ancestor)||find_ancestors(root->right,target,ancestor)){
            return true;
        }
        ancestor.pop_back();
        return false;
        

    }
};