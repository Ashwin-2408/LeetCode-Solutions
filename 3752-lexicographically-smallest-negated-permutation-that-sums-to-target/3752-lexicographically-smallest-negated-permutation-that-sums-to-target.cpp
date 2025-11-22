class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long max_sum=(((long long)n*(n+1))/2);
        if(target>max_sum || target<-max_sum){
            return {};
        }
        if((abs(max_sum-target)%2)==1){
            return {};
        }
        long long needed=max_sum-target;
        vector<int> ans;
        for(int i=n;i>=1;i--){
            if(2*i<=needed){
                ans.push_back(-i);
                needed-=2*i;
            }
            else{
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};