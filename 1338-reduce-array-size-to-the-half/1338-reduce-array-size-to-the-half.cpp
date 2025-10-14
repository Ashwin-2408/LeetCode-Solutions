class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mpp;
        int n=arr.size();
        for(auto it: arr){
            mpp[it]++;

        }
        priority_queue<int> pq;
        for(auto it: mpp){
            pq.push(it.second);
        }
        int ans=0;
        int curr=0;
        while(!pq.empty() && curr<(n/2)){
            ans++;
            curr+=pq.top();
            pq.pop();
        }
        return ans;
        
    }
};