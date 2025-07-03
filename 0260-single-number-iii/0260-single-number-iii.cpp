class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xo=0;
        for(auto it : nums){
            xo=xo^it;
        }
        int diff_bit=xo & -xo;
       
        
        int num1=0;
        int num2=0;
        for(auto it : nums){
            if(diff_bit & it){
                num1=num1^it;
                
            }
            else{
                num2=num2^it;
            }

        }
        return {num1,num2};
        
    }
};