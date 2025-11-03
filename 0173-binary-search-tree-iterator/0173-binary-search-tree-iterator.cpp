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
class BSTIterator {
public:
    stack<int> s;
    void push_elements(TreeNode* root,stack<int>& st){
        if(root==nullptr){
            return;
        }
        push_elements(root->right,st);
        
        st.push(root->val);
        push_elements(root->left,st);
        
    }
    BSTIterator(TreeNode* root) {
        push_elements(root,s);
        
        
    }
    
    int next() {
        int x=s.top();
        s.pop();
        return x;
        

        
    }
    
    bool hasNext() {
        if(!s.empty()){
            return true;
        }
        return false;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */