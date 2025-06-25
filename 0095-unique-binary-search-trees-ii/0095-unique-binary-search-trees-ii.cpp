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
    vector<TreeNode*> generateTrees(int n) {

        vector<TreeNode*> ans = helper(1,n);
        return ans;

        
    }
    vector<TreeNode*> helper(int start,int end){
        vector<TreeNode*> Trees;
        if(start>end){
            Trees.push_back(nullptr);


        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left_sub_tree=helper(start,i-1);
            vector<TreeNode*> right_sub_tree=helper(i+1,end);

            for(auto it:left_sub_tree){
                for(auto ele:right_sub_tree){
                    TreeNode* root= new TreeNode(i);
                    root->left=it;
                    root->right=ele;
                    Trees.push_back(root);
                }
            }
        }
        return Trees;

    }
};