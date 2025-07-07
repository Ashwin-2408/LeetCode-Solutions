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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* ans=construct(nums,0,nums.size()-1);
        return ans;
        

        
    }
    TreeNode* construct(vector<int>& nums,int i,int j){
        if(i>j){
            return nullptr;
        }
        int maximum=INT_MIN;
        int index=-1;
        for(int k=i;k<=j;k++){
            if(nums[k]>maximum){
                maximum=nums[k];
                index=k;
            }

        }
        TreeNode* root=new TreeNode(maximum);
        root->left=construct(nums,i,index-1);
        root->right=construct(nums,index+1,j);
        return root;
        

    }
};