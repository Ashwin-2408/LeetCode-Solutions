class Solution {
public:
    vector<bool> sieve;
    int distinctPrimeFactors(vector<int>& nums) {
        sieve.resize(1e4+1,true);
        set<int> num;
        int n=nums.size();
        for(int i=2;i*i<=1e4;i++){
            if(sieve[i]==true){
                for(int j=i*i;j<=1e4;j+=i){
                    sieve[j]=false;
                }
            }
        }
        for(auto it: nums){
            for(int i=2;2*i<=it;i++){
                if(sieve[i]==true && it%i==0 ){
                    num.insert(i);
                }
            }
            if(sieve[it]){
                num.insert(it);
            }
        }
        return num.size();
        
    }
};