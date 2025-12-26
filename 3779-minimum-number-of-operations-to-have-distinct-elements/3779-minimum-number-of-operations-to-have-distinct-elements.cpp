class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        int n=nums.size();
        int ops=0;
        for(int i=0;i<nums.size();i+=3){
            if(n-i==mpp.size()){
                return ops;
            }
            for(int j=i;j<min(i+3,n);j++){
                mpp[nums[j]]--;
                if(mpp[nums[j]]==0){
                    mpp.erase(nums[j]);
                }
            }
            ops++;



        }
        return ops;
        
    }
};