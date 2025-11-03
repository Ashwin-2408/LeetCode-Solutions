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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        bool left_to_right=true;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> temp(q.size(),0);
            
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                int index;
                if(left_to_right){
                    index=i;
                }
                else{
                    index=size-1-i;
                }
                temp[index]=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
               
                
            }
            ans.push_back(temp);
            left_to_right=!left_to_right;
        }
        return ans;
        
    }
};