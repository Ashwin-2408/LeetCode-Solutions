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
    int amountOfTime(TreeNode* root, int start) {
        vector<int> node_vals;
        find_nodes(root,node_vals);
        int total_nodes=*max_element(node_vals.begin(),node_vals.end());
        vector<vector<int>> edges(total_nodes+1);
        recurse(root,root->left,edges);
        recurse(root,root->right,edges);
        int ans=0;
        queue<int> q;
        q.push(start);
        vector<bool> visited(total_nodes,false);
        visited[start]=true;
        while(!q.empty()){
            int max_size=q.size();
            ans++;
            for(int i=0;i<max_size;i++){
                int node=q.front();
                q.pop();
                for(auto it:edges[node]){
                    if(!visited[it]){
                        visited[it]=true;
                        q.push(it);
                    }
                }
                
            }
        }
        return ans-1;


        
    }
    void find_nodes(TreeNode* root,vector<int>& nodes){
        if(root==nullptr){
            return ;
        }
        nodes.push_back(root->val);
        find_nodes(root->left,nodes);
        find_nodes(root->right,nodes);
        
    }
    void recurse(TreeNode* parent,TreeNode* root,vector<vector<int>> & edges){
        if(root==nullptr){
            return;
        }
        edges[parent->val].push_back(root->val);
        edges[root->val].push_back(parent->val);
        recurse(root,root->left,edges);
        recurse(root,root->right,edges);


    }
};