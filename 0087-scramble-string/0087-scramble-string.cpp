class Solution {
public:
    unordered_map<string,bool> dp;
    bool isScramble(string s1, string s2) {
        if(s1==s2){
            return true;
        }
        if(s1.size()!=s2.size()){
            return false;
        }
        string key=s1+" "+s2;
        if(dp.find(key)!=dp.end()){
            return dp[key];
        }
        int n=s1.size();
        for(int i=1;i<n;i++){
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i))){
                return dp[key]=true;
            }
            if(isScramble(s1.substr(0,i),s2.substr(n-i)) && isScramble(s1.substr(i),s2.substr(0,n-i))){
                return dp[key]=true;
            }
        }

        return dp[key]=false;
    }
};