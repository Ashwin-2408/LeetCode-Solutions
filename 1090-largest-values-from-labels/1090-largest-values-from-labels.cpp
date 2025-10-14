class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<values.size();i++){
            pq.push({values[i],labels[i]});
            
        }
        unordered_map<int,int> label_used;
        int ans=0;
        while(!pq.empty() && numWanted>0){
            int label=pq.top().second;
            int value=pq.top().first;
            pq.pop();
            label_used[label]++;
            if(label_used[label]<=useLimit){
                ans+=value;
                numWanted--;
            }
        }
        return ans;

    }
};