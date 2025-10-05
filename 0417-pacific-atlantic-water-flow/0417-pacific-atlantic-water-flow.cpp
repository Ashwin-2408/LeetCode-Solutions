class Solution {
public:
    vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> reachable1(n,vector<int> (m,0));
        vector<vector<int>> reachable2(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    reachable1[i][j]=1;
                    dfs(heights,reachable1,i,j);
                    
                }
            }
        }
     
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==n-1 || j==m-1){
                   
                    reachable2[i][j]=1;
                    
                    dfs(heights,reachable2,i,j);
                    
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(reachable1[i][j]==1 && reachable2[i][j]==1){
                    ans.push_back({i,j});
                }
            }
            cout << endl;
        }
        return ans;

        
        
    }
    void dfs(vector<vector<int>>& heights,vector<vector<int>>& reachable,int i,int j){
        int n=heights.size();
        int m=heights[0].size();
        for(auto it: dir){
            int new_x=i+it.first;
            int new_y=j+it.second;
            if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && !reachable[new_x][new_y] && heights[new_x][new_y]>=heights[i][j]){
                
                reachable[new_x][new_y]=1;
                dfs(heights,reachable,new_x,new_y);
            }
        }
        
        
    }
};