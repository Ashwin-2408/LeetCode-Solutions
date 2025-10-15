class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        set<string> s;
        map<string,int> mpp;
        for(auto it: responses){
            s.clear();
            for(auto strings:it){
                s.insert(strings);
            }
            for(auto ele:s){
                mpp[ele]++;
            }
        }
        int max_value=0;
        string ans="";
        for(auto it: mpp){
            if(it.second>max_value){
                ans=it.first;
                max_value=it.second;
            }
        }
        return ans;
    }
};