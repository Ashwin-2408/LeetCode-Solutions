class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>> pq;
        for(auto it: classes){
            pq.push({(double)(it[0]+1)/(it[1]+1)-((double)it[0]/it[1]),{it[0],it[1]}});

        }
        while(extraStudents>0){
            int pass=pq.top().second.first+1;
            int total=pq.top().second.second+1;
            pq.pop();
            pq.push({(((double)pass+1)/(total+1))-((double)(pass)/(total)),{pass,total}});
            extraStudents--;
        }
        double ans=0;
        while(!pq.empty()){
            ans+=(double)pq.top().second.first/pq.top().second.second;
            pq.pop();
        }
        return ans/classes.size();

        
    }
};