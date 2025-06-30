class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mpp;
        mpp[0]=1;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int mod=sum%k;
            if(mod<0){
                mod+=k;
            }
            if(mpp.find(mod)!=mpp.end()){
                count+=mpp[mod];
            }
            mpp[mod]++;




        }
        return  count;
        
    }
};