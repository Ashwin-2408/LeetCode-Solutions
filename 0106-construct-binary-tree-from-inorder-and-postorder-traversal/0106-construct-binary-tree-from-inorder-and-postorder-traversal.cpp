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
    unordered_map<int,int> inorder_index;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        for(int i=0;i<inorder.size();i++){
            inorder_index[inorder[i]]=i;
        }
        int index=n-1;
        return construct_tree(inorder,postorder,index,0,n-1);
        

        
    }
    TreeNode* construct_tree(vector<int>& inorder,vector<int>& preorder,int &index,int left,int right){
        if(left>right){
            return nullptr;

        }
        TreeNode* node= new TreeNode(preorder[index]);
        int split=inorder_index[node->val];
        index--;
        node->right=construct_tree(inorder,preorder,index,split+1,right);
        node->left=construct_tree(inorder,preorder,index,left,split-1);
        
        return node;


    }
};