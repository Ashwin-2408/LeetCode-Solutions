class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        if(n==1){
            return {};
        }
        vector<bool> primes(n + 1, true);
        primes[0] = false;
        primes[1] = false;
        for (int i = 2; i * i < n + 1; i++) {
            if (primes[i] == true) {
                for (int j = i * i; j < n + 1; j += i) {
                    primes[j] = false;
                }
            }
        }
        vector<vector<int>> ans;
        int i=2;
        for ( i ; i <= (n) / 2; i++) {
            if (primes[n - i] == true && primes[i]==true) {
                ans.push_back({i, n - i});
            }
        }
        
        return ans;
    }
};