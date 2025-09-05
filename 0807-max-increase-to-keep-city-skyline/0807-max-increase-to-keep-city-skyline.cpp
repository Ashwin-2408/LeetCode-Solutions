class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> row(grid.size(),0);
        vector<int> col(grid[0].size(),0);
        for(int i=0;i<grid.size();i++){
            row[i]=*max_element(grid[i].begin(),grid[i].end());
        }
        for(int i=0;i<grid.size();i++){
            int maximum_element=0;
            for(int j=0;j<grid.size();j++){
                maximum_element=max(maximum_element,grid[j][i]);

            }
            col[i]=maximum_element;
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                ans+=(min(row[i],col[j])-grid[i][j]);
            }
        }
        return ans;
        
    }
};