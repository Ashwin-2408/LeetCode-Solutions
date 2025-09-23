class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,int>,vector<pair<float,int>>, greater<pair<float,int>>> pq;
        for(int i=0;i<points.size();i++){
            float distance=0;
            distance=sqrt(pow(points[i][0],2)+pow(points[i][1],2));
            pq.push({distance,i});
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            ans.push_back(points[pq.top().second]);
            pq.pop();

        }
        return ans;
    }
};