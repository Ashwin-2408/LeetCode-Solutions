class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        for(auto it:bookings){
            for(int i=it[0]-1;i<=it[1]-1;i++){
                ans[i]+=it[2];
            }
        }
        return  ans;
        
    }
};