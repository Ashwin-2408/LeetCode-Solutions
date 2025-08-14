class Solution {
public:
    string largestGoodInteger(string nums) {
        string ans="";
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==nums[i+1] && nums[i]==nums[i+2]){
                if(ans==""){
                    ans=nums.substr(i,3);
                }
                else{
                    if((ans[0]-'0')<(nums[i]-'0')){
                        ans=nums.substr(i,3);
                    }
                }
                
            }
        }
        return ans;
        
    }
};