class Solution {
public:
    long long ans;
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        ans=LLONG_MAX;
        dfs(0,0,waitCost,m,n,0,1);
        return ans;
        
    }
    void dfs(int i, int j,vector<vector<int>>& waitCost,int m,int n,long long cost,int time){
        if(i>=m || j>=n){
            return;
        }
        if(i==m-1 && j==n-1){
            int val=(i+1)*(j+1);
            cost+=val;
            
            ans=min(ans,cost);
            return ;
        }
        if(time%2==1){
            int val=(i+1)*(j+1);
            dfs(i+1,j,waitCost,m,n,cost+val,time+1);
            dfs(i,j+1,waitCost,m,n,cost+val,time+1);
        }
        else{
            dfs(i,j,waitCost,m,n,cost+waitCost[i][j],time+1);
        
        }


    }
};