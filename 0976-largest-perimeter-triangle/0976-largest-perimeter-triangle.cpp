class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int perimeter=0;
        for(int i=0;i<nums.size()-2;i++){
            int side=nums[i]+nums[i+1];
            for(int j=i+2;j<nums.size();j++){
                if(nums[j]<side){
                    perimeter=max(perimeter,nums[j]+side);
                }
                else{
                    break;
                }

            }
            
        }
        return perimeter;
        
    }
};