class Solution {
public:
    int dp[12][2][12];
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        string s=to_string(n);
        int ans=recurse(s,0,1,0);
        return  ans;
        
    }
    int recurse(string&s,int index,int tight,int cnt){
        if(index==s.size()){
            return cnt;
        }
        if(dp[index][tight][cnt]!=-1){
            return dp[index][tight][cnt];
        }
        int limit=(tight)?(s[index]-'0'):9;
        int ans=0;
        for(int i=0;i<=limit;i++){
            int new_tight=tight&(i==s[index]-'0');
            if(i==1){
                ans+=recurse(s,index+1,new_tight,cnt+1);

            }
            else {
                ans+=recurse(s,index+1,new_tight,cnt);
            }
            
            
        }
        return dp[index][tight][cnt]=ans;

    }
};