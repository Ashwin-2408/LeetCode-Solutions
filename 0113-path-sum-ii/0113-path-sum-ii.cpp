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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
            return {};
        }
        vector<int> curr;
        int sum=0;
        vector<vector<int>> ans;
        path(root,targetSum,sum,curr,ans);
        return ans;


        
    }
    void path (TreeNode* root,int targetSum,int curr_sum,vector<int>& curr,vector<vector<int>>&ans){
        if(root==nullptr){
            if(curr_sum==targetSum){
                ans.push_back(curr);
            }
            return;
        }
        curr_sum+=root->val;
        curr.push_back(root->val);
        if(root->left && root->right){
            path(root->left,targetSum,curr_sum,curr,ans);
            path(root->right,targetSum,curr_sum,curr,ans);

        }
        else if(root->left){
            path(root->left,targetSum,curr_sum,curr,ans);

        }
        else if(root->right){
            path(root->right,targetSum,curr_sum,curr,ans);

        }
        else{
            path(root->right,targetSum,curr_sum,curr,ans);

        }
        curr_sum-=root->val;
        curr.pop_back();
    }
};