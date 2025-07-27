class Solution {
public:
    int countHillValley(vector<int>& nums) {
        bool increasing =true;
        int i=0;
        int count=0;
        while(nums[i]==nums[i+1]){
            i++;
        }
        i++;
        if(i<nums.size() && nums[i]-nums[i-1]<0){
            increasing =false;
            i++;
        }
        else{
            i++;
        }
        while(i<nums.size()){
            if(nums[i]-nums[i-1]>0 && !increasing){
                count++;
                increasing=!increasing;
            }
            else if(nums[i]-nums[i-1]<0 && increasing){
                count++;
                increasing=!increasing;
            }
            i++;

        }
        return count;

        
    }
};