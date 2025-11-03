class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adjlist(isConnected.size());
        int n=isConnected.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(isConnected[i][j]==1){
                    adjlist[i].push_back(j);
                }
            }
        }
        vector<bool> visited(isConnected.size(),false);
        int province=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adjlist);
                province++;
            }
        }
        return province;
        
    }
    void dfs(int node,vector<bool>& visited,vector<vector<int>> & adjlist){
        visited[node]=true;
        for(auto it: adjlist[node]){
            if(!visited[it]){
                
                dfs(it,visited,adjlist);
            }
        }

    }
};