class Solution {
public:
    int search(vector<int> & nums,int l,int r,int val){
        while(l<r){
            int mid=l +(r-l)/2;
            if(nums[mid]>=val){
                r=mid;
            }
            else{
                l=mid+1;
            }

        }
        return l;
    }
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                int index=search(nums,j+1,nums.size(),nums[i]+nums[j]);
                count+=(index-j-1);
            }
        }
        return count;
       
    }

};