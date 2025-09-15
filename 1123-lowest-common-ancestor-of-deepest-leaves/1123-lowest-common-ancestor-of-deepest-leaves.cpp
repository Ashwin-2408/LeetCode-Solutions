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
    TreeNode* deepestleft=nullptr;
    TreeNode* deepestright=nullptr;
    int max_left_depth=-1;
    int max_right_depth=-1;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        deep_leaves(root,0,false);
        if(max_left_depth == max_right_depth){
            return LCA(root,deepestleft,deepestright);

        }
        if(deepestleft){
            return deepestleft;
        }
        else{
            return deepestright;
        }
        

        
    }
    TreeNode* LCA(TreeNode* root,TreeNode* p, TreeNode* q){
        if(root==nullptr ||root==p || root==q){
            return root;
        }
        TreeNode* left=LCA(root->left,p,q);
        TreeNode* right=LCA(root->right,p,q);
        if(left && right){
            return root;
        }
        if(left){
            return left;
        }
        else{
            return right;
        }
    }
    void deep_leaves(TreeNode* root,int depth,bool isleft){
        if(!root){
            return ;
        }
        if(!root->left && !root->right){
            if(isleft && depth>max_left_depth){
                deepestleft=root;
                max_left_depth=depth;
            }
            else if(!isleft && depth>max_right_depth){
                deepestright=root;
                max_right_depth=depth;
            }
        }

        deep_leaves(root->left,depth+1,true);
        deep_leaves(root->right,depth+1,false);
    }
};