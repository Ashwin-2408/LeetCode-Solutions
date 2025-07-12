/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* curr=head;
        while(curr){
            nodes.push_back(curr);
            curr=curr->next;
        }
        TreeNode* root=create_tree(nodes,0,nodes.size()-1);
        return root;
        
    }
    TreeNode* create_tree(vector<ListNode*> nodes,int start,int end){
        if(start>end){
            return nullptr;
        }
        int mid=start + (end-start)/2;
        TreeNode* root = new TreeNode;
        root->val=nodes[mid]->val;
        root->left=create_tree(nodes,start,mid-1);
        root->right=create_tree(nodes,mid+1,end);
        return root;

    }
};