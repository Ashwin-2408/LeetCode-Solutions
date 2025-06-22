class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        map<int,int> mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        for(auto it: mpp){
            if(is_prime(it.second) && it.second>1){
                return true;
            }
        }
        return false;
        
        
    }
    bool is_prime(int x){
        for(int i=2;i<=sqrt(x);i++){
            if(x%i==0){
                return false;
            }
        }
        return true;
    }
};