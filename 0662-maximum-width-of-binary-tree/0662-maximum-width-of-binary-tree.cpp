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
    int widthOfBinaryTree(TreeNode* root) {
        long long width=0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,1});
        while(!q.empty()){
            int size=q.size();
            long long first;
            long long last;
            long long minindex=q.front().second;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front().first;
                long long index=q.front().second-minindex;
                q.pop();
                if(i==0){
                    first=index;
                }
                if(i==size-1){
                    last=index;

                }
                if(curr->left){
                    q.push({curr->left,index*2});
                }
                if(curr->right){
                    q.push({curr->right,index*2+1});
                }
                
            }
            width=max(width,last-first+1);
        }
        
        return width;
    }
};