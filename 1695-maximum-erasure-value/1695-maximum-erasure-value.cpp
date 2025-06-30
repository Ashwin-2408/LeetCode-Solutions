class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int i=0;
        int sum=0;
        int max_sum=0;
        for(int j=0;j<nums.size();j++){
            mpp[nums[j]]++;
            int length=j-i+1;
            sum+=nums[j];
            if(length==mpp.size()){
                max_sum=max(sum,max_sum);

            }
            while(length!=mpp.size() && i<=j){
                
                mpp[nums[i]]--;
                sum-=nums[i];
                if(mpp[nums[i]]==0){
                    mpp.erase(nums[i]);
                }
                i++;
                length=j-i+1;
            }
        }
        return  max_sum;
    }
};