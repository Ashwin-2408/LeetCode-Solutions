class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j == 0 || i == 0 || i == n - 1 || j == m - 1) {
                    if (visited[i][j] == 0 && grid[i][j] == 0) {
                        dfs(grid, i, j, visited);
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(visited[i][j]==0 && grid[i][j]==0){
                    ans++;
                    dfs(grid,i,j,visited);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& grid, int i, int j,
             vector<vector<int>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || i == n || j < 0 || j == m || grid[i][j] == 1 ||
            visited[i][j] == 1) {
            return;
        }
        visited[i][j] = 1;
        for (auto it : dir) {
            int new_x = i + it.first;
            int new_y = j + it.second;
            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m &&
                grid[new_x][new_y] != 1 && visited[new_x][new_y] != 1) {
                dfs(grid, new_x, new_y, visited);
            }
        }
    }
}

;