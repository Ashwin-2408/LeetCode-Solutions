class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        vector<int> diff(n+1,0);
        for(auto it:bookings){
            diff[it[0]-1]+=it[2];
            diff[it[1]]-=it[2];

        
        }
        ans[0]=diff[0];
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]+diff[i];
        }
        return ans;

        
        
    }
};