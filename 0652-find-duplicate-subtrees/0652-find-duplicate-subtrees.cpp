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
    string serialize_subtree(TreeNode* root,unordered_map<string,int>& subtrees,vector<TreeNode*>& duplicates){
        if(root==nullptr){
            return "#";
        }
        string left= serialize_subtree(root->left,subtrees,duplicates);
        string right=serialize_subtree(root->right,subtrees,duplicates);
        string s=left+","+right+","+to_string(root->val);
        if(subtrees[s]==1){
            duplicates.push_back(root);
        }
        subtrees[s]++;
        return s;

    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> subtrees;
        vector<TreeNode*> duplicates;
        serialize_subtree(root,subtrees,duplicates);
        return duplicates;


        
    }
};