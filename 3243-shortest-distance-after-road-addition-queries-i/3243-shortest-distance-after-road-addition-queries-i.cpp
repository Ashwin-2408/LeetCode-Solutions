class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<int> ans;
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        for(auto it: queries){
            adj[it[0]].push_back(it[1]);
            ans.push_back(djikstra(adj,n));
        

        }
        return ans;
    }
    int djikstra(vector<vector<int>> adj,int n){
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
           
            pq.pop();
           
            for(auto it: adj[node]){
                if( dist[it]>=d+1){
                    dist[it]=d+1;
                    pq.push({d+1,it});
                    
                }
            }
        }
        return dist[n-1];


    }
};