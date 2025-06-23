class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total=0;
        for(auto it :grid){
            for(auto ele:it){
                total+=ele;
            }
        }
        if(total%2!=0){
            return false;
        }
        int required=total/2;
        int row_sum=0;
        int col_sum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                row_sum+=grid[i][j];
            }
            if(row_sum==required){
                return true;
            }
            if(row_sum>required){
                break;
            }

        }
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                col_sum+=grid[j][i];
            }
            if(col_sum==required){
                return true;
            }
            if(col_sum>required){
                break;
            }
        }
        return false;
        
    }
};