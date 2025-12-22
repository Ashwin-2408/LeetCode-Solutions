class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long> alpha(26,0);
        for(int i=0;i<s.size();i++){
            alpha[s[i]-'a']+=cost[i];
        }
        sort(alpha.begin(),alpha.end());
        long long ans=0;
        for(int i=0;i<25;i++){
            ans+=alpha[i];
        }
        return ans;
        
    }
};