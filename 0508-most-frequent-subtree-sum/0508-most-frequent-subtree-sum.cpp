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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mpp;
        mpp[root->val]++;
        int max_freq=1;
        find_sum()
        
    }
    void find_sum(TreeNode* root,unordered_map<int,int>&mpp,int &max_freq,int sum){
        if(!root){
            mpp[sum]++;
            if(mpp[sum]>max_freq){
                max_freq=mpp[sum];
            }
            return ;
        }
        mpp[sum]++;
        if(mpp[sum]>max_freq){
                max_freq=mpp[sum];
        }
        find_sum(root->left,mpp,max_freq,sum+root->val);
        find_sum(root->left,mpp,max_freq,sum+root->val);
        find_sum(root->left,mpp,max_freq,sum+root->val);
        
    }
};