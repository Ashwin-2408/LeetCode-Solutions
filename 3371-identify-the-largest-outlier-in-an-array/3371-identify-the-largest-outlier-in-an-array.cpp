class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        int outlier=INT_MIN;
        int total=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<nums.size();i++){
            int candidate=total-2*nums[i];
            if(mpp.count(candidate)){
                if(candidate!=nums[i] || mpp[nums[i]]>1){
                    outlier=max(candidate,outlier);


                }
            }
        }
        return outlier;
    }
};