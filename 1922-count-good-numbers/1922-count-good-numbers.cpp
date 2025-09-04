class Solution {
public:
    int MOD=1e9+7;
    int countGoodNumbers(long long n) {
        long long ans=0;
        long long pow_5=n-(n/2);
        long long pow_4=n/2;
        cout << n/2;
        long long val_5=power(5,pow_5);
        long long val_4=power(4,pow_4);
        ans=(val_4*val_5)%MOD;
        return ans;
        
    }
    long long power(long long n,long long x){
        if(x==0){
            return 1;
        }
        long long res=1;
        while(x>0){
            if(x%2==1){
                res=(res*n)%(MOD);
            }
            n=((long long)(n*n)%(MOD));
            x=x/2;
        }
        return res%MOD;
    }
};