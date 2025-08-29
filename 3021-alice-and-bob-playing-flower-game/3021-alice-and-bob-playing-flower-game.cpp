class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans=0;
        int even1=n/2;
        int even2=m/2;
        int odd1=n-even1;
        int odd2=m-even2;
        ans=even1*odd2 + even2*odd1;


        return ans;
        
    }
};