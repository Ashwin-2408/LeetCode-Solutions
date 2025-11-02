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
    unordered_map<int,int> mpp;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root){
            return {};
        }
        for(auto it:to_delete){
            mpp[it]++;
        }
        vector<TreeNode*> ans;
        if(mpp.count(root->val)==0){
            solve(root,ans,false);
            ans.push_back(root);

        }
        else{
            solve(root,ans,true);

        }
        

        
        return ans;
        
        
    }
    void solve(TreeNode* root,vector<TreeNode*>& ans,bool add){
        if(root==nullptr){
            return;
        }
        if(root->left){
            
            if(mpp.count(root->left->val)==1){
                solve(root->left,ans,true);
                
                root->left=nullptr;
            }
            else{
                if(add){
                    ans.push_back(root->left);
                }
                solve(root->left,ans,false);
            }
        }
        if(root->right){
            if(mpp.count(root->right->val)==1){
                solve(root->right,ans,true);
                
                root->right=nullptr;
            }
            else{
                if(add){
                    ans.push_back(root->right);
                }
                solve(root->right,ans,false);
            }

        }

    }
};