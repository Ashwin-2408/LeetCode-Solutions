class Solution {
public:
    vector<vector<int>> dp;
    int countArrangement(int n) {
        dp.resize(n+1,vector<int>((1<<n),-1));
        
       int bitmask=0;
       return recurse(n,bitmask,n);

        
    }
    int recurse(int n,int bitmask,int count_num){
        if(n==0){
            return 1; 
        }
        if(dp[n][bitmask]!=-1){
            return  dp[n][bitmask];
        }
        int ans=0;
        for(int i=1;i<=count_num;i++){
            if(!(bitmask & (1<<i-1))){
                if(n%i==0 || i%n==0){
                   ans+= recurse(n-1,bitmask | (1<<(i-1)),count_num);
                }
            }
        }
        return dp[n][bitmask]=ans;

    }
};