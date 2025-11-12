class Solution {
public:
    int gcd(int a,int b){
        if(a<b){
            return gcd(b,a);
        }
        while(b!=0){
            
            int temp=b;
            b=a%b;
            a=temp;

        }
        return a;
    }
    int minOperations(vector<int>& nums) {
        int ones=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                ones++;
            }
        }
        int minimum_length=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int g=nums[i];
            for(int j=i+1;j<nums.size();j++){
                g=gcd(g,nums[j]);
                if(g==1){
                    minimum_length=min(minimum_length,j-i+1);
                    break;
                }

                
            }
        }
        if(minimum_length==INT_MAX && ones==0){
            return -1;
        }

        return minimum_length-1 +(nums.size()-ones-1);
        
    }
};