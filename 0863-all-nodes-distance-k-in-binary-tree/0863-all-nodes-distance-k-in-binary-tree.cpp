/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> nodes;
        find_total(root,nodes);
        int total_nodes=*max_element(nodes.begin(),nodes.end());
        vector<vector<int>> edges(total_nodes+1);
        construct_graph(root,root->left,edges);
        construct_graph(root,root->right,edges);
        queue<int> q;
        q.push(target->val);
        vector<bool> visited(total_nodes,false);
        visited[target->val]=true;
        int iteration=-1;
        vector<int> ans;
        while(!q.empty()){
            iteration++;
            int max_size=q.size();
            for(int i=0;i<max_size;i++){
                int node=q.front();
                if(iteration==k){
                    ans.push_back(node);
                }
                q.pop();
                for(auto it: edges[node]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it]=true;
                    }
                }
            }
            if(iteration==k){
                break;
            }

        } 
        return ans;

        
    }
    void construct_graph(TreeNode* parent, TreeNode* root,vector<vector<int>> & edges){
        if(root==nullptr){
            return ;
        }
        edges[parent->val].push_back(root->val);
        edges[root->val].push_back(parent->val);
        construct_graph(root,root->left,edges);
        construct_graph(root,root->right,edges);
    }
    void find_total(TreeNode* root,vector<int>& nodes){
        if(root==nullptr){
            return ;
        }
        nodes.push_back(root->val);
        find_total(root->left,nodes);
        find_total(root->right,nodes);
    }
};