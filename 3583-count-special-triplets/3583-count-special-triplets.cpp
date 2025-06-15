class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int> suffix;
        unordered_map<int,int> prefix;

        for (auto it: nums){
            suffix[it]++;
            
        }
        int result=0;
        int mod = 1e9+7;
        for(int i=0;i<nums.size();i++){
            suffix[nums[i]]--;
            
            int required= 2* nums[i];
            long long count_pre=prefix[required];
            long long count_suf=suffix[required];
            
            result=(result+((count_pre*count_suf)%mod))%mod;
            prefix[nums[i]]++;
            
        }
        return result;
        
    }
};