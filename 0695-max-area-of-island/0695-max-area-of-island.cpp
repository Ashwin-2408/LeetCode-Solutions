class Solution {
    vector<vector<int>> visited;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        visited.assign(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dfs(0,i,grid);
        }
        for(int i=0;i<m;i++){
            dfs(n-1,i,grid);
        }
        for(int i=0;i<m;i++){
            dfs(n-1,i,grid);
        }
        
    }
};