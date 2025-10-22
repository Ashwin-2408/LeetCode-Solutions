class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto it: piles){
            pq.push(it);
        }
        while(!pq.empty() && k>0){
            pq.push(ceil((float)pq.top()/2));
            pq.pop();
            k--;
        }
        int ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};