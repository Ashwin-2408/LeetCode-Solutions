class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n,true);
        for(int p=2;p*p<n;p++){
            if(primes[p]){
                for(int i=p*p;i<n;i+=p){
                    primes[i]=false;
                }
            }
        }
        int count=0;
        for(int i=2;i<n;i++){
            if(primes[i]){
                count++;
            }
        }
        return count;
        
    }
};