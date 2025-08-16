class Solution {
public:
    int maximum69Number (int num) {
        vector<int> nums;
        while(num>0){
            nums.insert(nums.begin(),num%10);
            num/=10;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==6){
                nums[i]=9;
                break;
            }
        }
        int ans=0;
        for(auto it: nums){
            ans*=10;
            ans+=it;
        }
        return ans;

        
    }
};