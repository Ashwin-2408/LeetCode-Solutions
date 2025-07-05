class Solution {
public:
    int findLucky(vector<int>& arr) {
        int count=0;
        unordered_map<int,int> mpp;
        for(auto it:arr){
            mpp[it]++;
        }
        for(auto iter:mpp){
            if(iter.first==iter.second){
                count=max(count,iter.first);
            }
        }
        if(count ==0){
            return -1;
        }
        return count;
    }
};