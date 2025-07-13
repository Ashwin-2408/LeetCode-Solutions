class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1){
            return -1;
        }
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};


        while(!q.empty()){
            int dist=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            
            q.pop();
            if(x==n-1 && y==m-1){
                return dist;
            }
            for(auto it:dir){
                int new_x=x+it.first;
                int new_y=y+it.second;
                if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && visited[new_x][new_y]==0 && grid[new_x][new_y]==0){
                    visited[new_x][new_y]=1;
                    q.push({dist+1,{new_x,new_y}});
                }
            }


        }
        return -1;
        
    }
};