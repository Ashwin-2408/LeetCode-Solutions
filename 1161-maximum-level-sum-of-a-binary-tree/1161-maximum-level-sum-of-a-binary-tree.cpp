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
    int maxLevelSum(TreeNode* root) {
        vector<long long> level_order;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int level=q.front().second;
            q.pop();
            if(level_order.size()<level){
                level_order.push_back(node->val);
            }
            else{
                level_order[level-1]+=node->val;
            }
            
            if(node->left){
                q.push({node->left,level+1});
            }
            if(node->right){
                q.push({node->right,level+1});
            }



        }
        int curr_val=INT_MIN;
        int ans=0;
        for(int i=0;i<level_order.size();i++){
            if(level_order[i]>curr_val){
                ans=i+1;
                curr_val=level_order[i];
        

            }


        }
        return ans;

        
    }
};