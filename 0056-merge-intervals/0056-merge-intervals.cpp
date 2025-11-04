class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int left=intervals[0][0];
        int right=intervals[0][1];
        vector<vector<int>> ans;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=right){
                right=max(intervals[i][1],right);
            }
            else{
                ans.push_back({left,right});
                left=intervals[i][0];
                right=intervals[i][1];

            }
        }
        ans.push_back({left,right});
        return ans;        
    }
};