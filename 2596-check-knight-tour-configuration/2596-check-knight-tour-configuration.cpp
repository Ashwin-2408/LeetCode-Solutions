class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        vector<pair<int,int>> directions{{2,1},{2,-1},{1,2},{1,-2},{-1,2},{-1,-2},{-2,1},{-2,-1}};


        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x=i;
                int y=j;
                int val=grid[i][j];
                if(val==(n*m)-1){
                    continue;

                }
                bool valid=false;
                for(auto it: directions){
                    int new_x=x+it.first;
                    int new_y=y+it.second;
                    if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && grid[new_x][new_y]==val+1){
                        valid=true;
                        break;
                    }

                }
                if(!valid){
                    return false;
                }
            }
        }
        return true;
        
    }
};