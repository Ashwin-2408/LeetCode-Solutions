class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int time=0;
        vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            bool rotten=false;
            int size=q.size();
       
            for(int i=0;i<size;i++){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(auto it: dir){
                int x1=x+it.first;
                int y1=y+it.second;
                if(x1>=0 && x1<n && y1>=0 && y1<m && grid[x1][y1]!=0 && grid[x1][y1]!=2){
                    grid[x1][y1]=2;
                    rotten=true;
                    q.push({x1,y1});

                }
            }
            if(rotten){
                time++;
            }
            }


        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
        
    }
};