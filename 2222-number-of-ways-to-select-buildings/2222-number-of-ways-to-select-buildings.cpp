class Solution {
public:
    long long numberOfWays(string s) {
        int n=s.size();
        vector<long long> suffix_zero(n,0),suffix_one(n,0),prefix_zero(n,0),prefix_one(n,0);
        if(s[0]=='0'){
            prefix_zero[0]=1;
        }
        else{
            prefix_one[0]=1;
        }

        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                prefix_one[i]=1+prefix_one[i-1];
                prefix_zero[i]=prefix_zero[i-1];
            }
            else{
                prefix_zero[i]=1+prefix_zero[i-1];
                prefix_one[i]=prefix_one[i-1];

            }

        }
         if(s[n-1]=='0'){
            suffix_zero[n-1]=1;
        }
        else{
            suffix_one[n-1]=1;
        }
        for(int i=n-2;i>=0;i--){
            if(s[i]=='1'){
                suffix_one[i]=1+suffix_one[i+1];
                suffix_zero[i]=suffix_zero[i+1];
            }
            else{
                suffix_zero[i]=1+suffix_zero[i+1];
                suffix_one[i]=suffix_one[i+1];

            }

        }
        long long ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                ans+=suffix_one[i]*prefix_one[i];
            }
            else{
                ans+=suffix_zero[i]*prefix_zero[i];

            }
        }
        return ans;
    }
};