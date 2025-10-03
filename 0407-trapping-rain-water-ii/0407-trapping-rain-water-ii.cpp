class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    pq.push({heightMap[i][j],i,j});
                    visited[i][j]=true;
                    
                }
            }
        }
        int level=0;
        int trapped_water=0;
        vector<pair<int,int>> dir ={{-1,0},{1,0},{0,1},{0,-1}};
        
        while(!pq.empty()){
            
            int x=pq.top()[1];
            int y=pq.top()[2];
            int val=pq.top()[0];
            pq.pop();
            if(val<level){
                trapped_water+=level-val;
            }
            level=max(level,val);
            for(auto it: dir){
                int new_x=x+it.first;
                int new_y=y+it.second;
                if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && visited[new_x][new_y]==false){
                    visited[new_x][new_y]=true;
                    pq.push({heightMap[new_x][new_y],new_x,new_y});
                }
            }
            
        }
        return trapped_water;
        
    }
};