class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj1(n);
        vector<vector<pair<int,int>>> adj2(n);
        for(auto it: redEdges){
            adj1[it[0]].push_back({1,it[1]});

        }
        for(auto it: blueEdges){
            adj2[it[0]].push_back({-1,it[1]});

        }
        vector<int> ans(n,INT_MAX);
        vector<int> visited1(n,-1);
        vector<int> visited2(n,-1);
        ans[0]=0;
        queue<vector<int>> q;
        q.push({0,0,0});
        while(!q.empty()){
            vector<int> temp=q.front();
            int u=temp[0];
            int w=temp[1];
            int d=temp[2];
            if(w==1){
                visited1[u]=1;

            }
            else if(w==-1){
                visited2[u]=1;

            }
            else{
                visited1[u]=1;
                visited2[u]=1;
            }
            
            q.pop();
            if(w==0){
               
                for(auto it:adj1[u]){
                    
                    q.push({it.second,it.first,d+1});
                
                }
                for(auto it:adj2[u]){
                    
                    q.push({it.second,it.first,d+1});
                    
                }
            }
            else{
              
               
                ans[u]=min(ans[u],d);
                if(w==1){
                for(auto it: adj2[u]){
                
                        if(visited2[it.second]==-1){
                        q.push({it.second,it.first,d+1});
                        }
                    
                }
                }
                else{
                    for(auto it: adj1[u]){
                
                        if(visited1[it.second]==-1){
                        q.push({it.second,it.first,d+1});
                        }
                    
                }

                }


            }


        }
        for(int i=0;i<n;i++){
            if(ans[i]==INT_MAX){
                ans[i]=-1;
            }
        }
        return ans;

        
    }
};