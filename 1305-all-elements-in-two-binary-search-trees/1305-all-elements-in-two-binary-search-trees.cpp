/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void
    push_left(priority_queue<pair<int, TreeNode*>, vector<pair<int, TreeNode*>>,
                             greater<pair<int, TreeNode*>>>& pq,
              TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            pq.push({curr->val, curr});
            curr = curr->left;
        }
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        priority_queue<pair<int, TreeNode*>, vector<pair<int, TreeNode*>>,
                       greater<pair<int, TreeNode*>>>
            pq;
        if (root1) {
            push_left(pq, root1);
        }
        if (root2) {
            push_left(pq, root2);
        }
        vector<int> ans;
        while (!pq.empty()) {
            int val = pq.top().first;
            TreeNode* node = pq.top().second;
            pq.pop();
            ans.push_back(val);
            
            push_left(pq, node->right);
            

        }
        return ans;
    }
};

