class Solution {
public:
    int numSplits(string s) {
        vector<int> prefix(s.size(),0),suffix(s.size(),0);
        unordered_map<int,int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
            prefix[i]=mpp.size();
        }
        mpp.clear();
        for(int i=s.size()-1;i>=0;i--){
            mpp[s[i]]++;
            suffix[i]=mpp.size();
        }
        int ans=0;
        for(int i=1;i<s.size();i++){
            if(prefix[i-1]==suffix[i]){
                ans+=1;
            }
        }
        return ans;
    }
};