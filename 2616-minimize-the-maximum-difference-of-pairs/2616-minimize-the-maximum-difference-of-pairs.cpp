class Solution {
public:
    int count_pairs(vector<int>& nums,int p){
        int pairs=0;
        for(int i=0;i<nums.size()-1;i++){
            if(abs(nums[i]-nums[i+1])<=p){
                pairs++;
                i++;
            }
            else{
                continue;
            }
        }
        return pairs;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int left=0;
        int right=nums[nums.size()-1];
        while(left<right){
            int mid= left +(right-left)/2;
            if(count_pairs(nums,mid)>=p){
                right=mid;
            }
            else{
                left=mid+1;
            }

        }
        return left;
        
    }
};