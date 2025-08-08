class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool first=false,second=false,third=false;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                return false;
            }
            else if(nums[i]<nums[i-1]){
                if(first && second==false){
                    second =true;
                }
                else if(first && second && third){
                    return false;
                }
                else if(first && second){
                    continue;
                }
                else{
                    return false;
                }

            }
            else{
                if(first==false){
                    first=true;
                }
                else if(first && second && third==false){
                    third=true;
                }
            }

        }
        if(first && second && third){
            return true;
        }
        return false;
        
    }
};