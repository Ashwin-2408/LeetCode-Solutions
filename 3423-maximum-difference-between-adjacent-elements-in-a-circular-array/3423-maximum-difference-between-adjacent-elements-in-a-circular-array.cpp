class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maximum=INT_MIN;
        if(abs(nums[nums.size()-1]-nums[0])>maximum){
            maximum=abs(nums[nums.size()-1]-nums[0]);
        }
        for(int i=0;i<nums.size()-1;i++){
            maximum=max(maximum,abs(nums[i]-nums[i+1]));
        }
        return maximum;
        
    }
};