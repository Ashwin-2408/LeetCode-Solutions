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
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> row_level;
        row_level_traversal(row_level,root,0);
         vector<int> ans;
        for(int i=0;i<row_level.size();i++){
            ans.push_back(*max_element(row_level[i].begin(),row_level[i].end()));

            
        }
        return ans;
    }
    void row_level_traversal(vector<vector<int>>& row_level,TreeNode* root,int level){
        if(root==nullptr){
            return;
        }
        if(row_level.size()<level+1){
            row_level.push_back({});
        }
        row_level[level].push_back(root->val);
        row_level_traversal(row_level,root->left,level+1);
        row_level_traversal(row_level,root->right,level+1);
    }
};