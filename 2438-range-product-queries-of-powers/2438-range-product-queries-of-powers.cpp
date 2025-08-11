class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod=1e9+7;
        vector<int> powers;
        int i=0;
        while(n>0){
            if(n&1 ==1){
                powers.push_back(pow(2,i));
            }
            n= n >> 1;
            i++;

        }
        vector<int> ans(queries.size(),0);
        for(int i=0;i<queries.size();i++){
            int l = queries[i][0];
            int r= queries[i][1];
            long long prod=1;
            while(l<=r){
                prod=(prod*powers[l])%mod;
                l++;

            }
            ans[i]=prod;
        }
        return ans;
        
        
    }
};