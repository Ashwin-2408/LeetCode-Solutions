class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if(nums.size()%k!=0){
            return false;
        }
        if(k==1){
            return true;
        }
        unordered_map<int,int> mpp;
        for(auto it: nums){
            mpp[it]++;
            if(mpp[it]>k){
                return false;
            }
        }
        if(nums.size()<=k){
            for(auto it: mpp){
                if(it.second>1){
                    return false;
                }
            }
        }
        return true;
        
    }
};