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
    void recoverTree(TreeNode* root) {
        vector<int> inorder_t;
        vector<TreeNode*> nodes;
        inorder(root,inorder_t,nodes);
        sort(inorder_t.begin(),inorder_t.end());
        for(int i=0;i<nodes.size();i++){
            if(nodes[i]->val!=inorder_t[i]){
                nodes[i]->val=inorder_t[i];
            }
        }
    }
    void inorder(TreeNode* root,vector<int>& inorder_t,vector<TreeNode*>&nodes){
        if(root==nullptr){
            return;
        }
        
        inorder(root->left,inorder_t,nodes);
        nodes.push_back(root);
        inorder_t.push_back(root->val);
        inorder(root->right,inorder_t,nodes);
        
    }
};