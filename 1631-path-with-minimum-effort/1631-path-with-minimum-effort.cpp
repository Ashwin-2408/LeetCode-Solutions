class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        vector<vector<int>> visited(n,vector<int>(m,INT_MAX));
        vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        visited[0][0]=1;
        int minimum_path=INT_MAX;

        while(!pq.empty()){
            int path=pq.top()[0];
            int r=pq.top()[1];
            int c=pq.top()[2];
            pq.pop();
            if(r==n-1 && c==m-1){
                minimum_path=min(minimum_path,path);
            }
            for(auto it: dir){
                int new_x=r+it.first;
                int new_y=c+it.second;
                if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && abs(heights[r][c]-heights[new_x][new_y])<visited[new_x][new_y]){
                    visited[new_x][new_y]=abs(heights[r][c]-heights[new_x][new_y]);
                    pq.push({max(path,abs(heights[r][c]-heights[new_x][new_y])),new_x,new_y});
                }
            }
            
        }
        if(minimum_path==INT_MIN){
            return 0;
        }
        return minimum_path;
        

        
    }
};