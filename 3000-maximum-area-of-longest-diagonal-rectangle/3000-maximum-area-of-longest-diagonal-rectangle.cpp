class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double prev_diagonal=0;
        int ans=0;
        for(auto it : dimensions){
            int x=it[0];
            int y=it[1];
            double diagonal=sqrt((x*x)+(y*y));
            if(diagonal>prev_diagonal){
                ans=(x*y);
                prev_diagonal=diagonal;
                
            }
            else if(diagonal==prev_diagonal){
                ans=max(ans,x*y);
            }
           

           }

        
        return ans;

        
    }
};