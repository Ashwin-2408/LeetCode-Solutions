class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> count(m,0);

        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                for(int j=0;j<m;j++){
                    int new_val=((grid[i][j]+1)%2);
                    grid[i][j]=new_val;
                }
            }
        }
        for(int i=0;i<m;i++){
            int count1=0;
            for(int j=0;j<n;j++){
                if(grid[j][i]==1){
                    count1++;
                }

            }
            count[i]=count1;

        }
        
        int ans=0;
        int power=m-1;
        for(auto it: count){
           
            ans+=max(it,n-it)*(pow(2,power));
            power--;

        }
        return ans;
        

        
    }
};