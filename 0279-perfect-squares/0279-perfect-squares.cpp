class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for(int i=1;i<=n;i++){
            if((i*i)<=n){
                squares.push_back(i*i);
            }
            else{
                break;
            }
        }
        vector<vector<int>> dp(squares.size()+1,vector<int>(n+1,0));
        for(int i=0;i<n+1;i++){
            dp[0][i]=INT_MAX;
        }
        for(int i=0;i<squares.size()+1;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<squares.size()+1;i++){
            for(int j=1;j<n+1;j++){
                if(squares[i-1]>j){
                    dp[i][j]=dp[i-1][j];

                }
                else{
                    dp[i][j]=min(1+dp[i][j-squares[i-1]],dp[i-1][j]);
                }
            }
        }
        for(auto it: dp){
            for(auto ele: it){
                cout <<  ele << " ";
            }
            cout << endl;
        }
        return dp[squares.size()][n];
    
    }
};