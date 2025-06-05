class Solution {
    vector<vector<int>> visited;
    vector<pair<int,int>> dir={{0,-1},{0,1},{1,0},{-1,0}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        visited.assign(n,vector<int>(m,0));
       
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]!=1){
                    int area=dfs(i,j,grid);
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
    int dfs(int r,int c,vector<vector<int>> & grid){
        
        if(grid[r][c]==0 || visited[r][c]==1){
            return 0;
        }
        visited[r][c]=1;
        grid[r][c]=0;
        int area = 1;
        
        for(auto it:dir){
            int new_x=it.first+r;
            int new_y=it.second+c;
            if(new_x>=0 && new_x<grid.size() && new_y>=0 && new_y<grid[0].size()){
                area+=dfs(new_x,new_y,grid);
            }
        }
        return area;
    }
};