class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mpp;
        for(auto it: s){
            mpp[it]++;
        }
        string ans="";
        for(auto it: order){
            if(mpp.count(it)){
                ans+=string(mpp[it],it);
                mpp.erase(it);
            }
        }
        for(auto it: mpp){
            ans+=string(it.second,it.first);
        }
        return ans;
        
    }
};