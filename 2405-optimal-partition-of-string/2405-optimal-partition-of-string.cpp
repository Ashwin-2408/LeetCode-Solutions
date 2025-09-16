class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int>mpp;
        int ans=0;
        for(auto it:s){
            if(!mpp.count(it)){
                mpp[it]++;
            }
            else{
                mpp.clear();
                ans++;
                mpp[it]++;
            }
        }
        return ans+1;
        
    }
};