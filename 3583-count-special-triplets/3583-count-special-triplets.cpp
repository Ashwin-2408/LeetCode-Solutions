class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int MOD=1e9+7;
        unordered_map<int,int> mpp;
        vector<long long> suffix(nums.size(),0);
        vector<long long> prefix(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(mpp.count(2*nums[i])){
                prefix[i]=mpp[2*nums[i]];
            }
            mpp[nums[i]]++;

        }
        mpp.clear();
        for(int i=nums.size()-1;i>=0;i--){
            if(mpp.count(2*nums[i])){
                suffix[i]=mpp[2*nums[i]];
            }
            mpp[nums[i]]++;

        }
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            ans=(ans+(prefix[i]*suffix[i])%MOD)%MOD;
        }
        return ans;
    }
};