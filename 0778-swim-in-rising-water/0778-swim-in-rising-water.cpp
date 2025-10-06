class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({grid[0][0],0,0});
        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> visited(n,vector<int>(m,-1));
        visited[0][0]=1;
        while(!pq.empty()){
            int t=pq.top()[0];
            int r=pq.top()[1];
            int c=pq.top()[2];
            pq.pop();
            if(r==n-1 && c==m-1){
                return t;
            }
            for(auto it: dir){
                int new_x=r+it.first;
                int new_y=c+it.second;
                if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && visited[new_x][new_y]==-1){
                    visited[new_x][new_y]=1;
                    pq.push({max(grid[new_x][new_y],t),new_x,new_y});

                }

            }

            

        }
        return -1;
      
    }
};