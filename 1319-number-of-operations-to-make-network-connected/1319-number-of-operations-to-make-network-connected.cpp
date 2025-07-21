class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int count=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==true){
                continue;
            }
            else{
                visited[i]=true;
                count++;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto it:adj[node]){
                        if(visited[it]==false){
                        visited[it]=true;
                        q.push(it);
                        }
                    }
                }
            }
        }
        return count-1;
    }
};