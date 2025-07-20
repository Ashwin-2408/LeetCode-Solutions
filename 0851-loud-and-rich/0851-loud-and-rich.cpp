class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>> adj(n);
        for(auto it: richer){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=i;
        }
        for(int i=0;i<n;i++){
            vector<bool> visited(n,false);
            queue<int> q;
            q.push(i);
            int minimum_quietness=INT_MAX;

            visited[i]=true;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                if(quiet[node]<minimum_quietness){

                    ans[i]=node;
                    minimum_quietness=min(minimum_quietness,quiet[node]);
                }
                for(auto it:adj[node]){
                    if(!visited[it]){
                        visited[it]=true;
                        q.push(it);

                    }
                    

                }
            }
            


            
        }
        return ans;
        
    }
};