class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mpp;
        for(auto it :s){
            mpp[it]++;
        }
        int odd=0;
        int even=INT_MAX;
        for(auto it : mpp){
            if(it.second%2==0 && it.second<even){
                even=it.second;
            }
            else if(it.second%2==1 && it.second>odd){
                odd=it.second;
            }

        }
        return(odd-even);
    }
};