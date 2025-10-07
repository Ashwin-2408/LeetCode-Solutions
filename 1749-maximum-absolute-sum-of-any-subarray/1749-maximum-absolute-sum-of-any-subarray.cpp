class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maximum_positive=0;
        int maximum_negative=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0){
                sum=0;
            }
            maximum_positive=max(maximum_positive,sum);
        }
        sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>0){
                sum=0;
            }
            maximum_negative=min(maximum_negative,sum);
        }
        return max(abs(maximum_negative),maximum_positive);
        
    }
};