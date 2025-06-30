class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score=0;
        priority_queue<int> pq;
        for(auto it: nums){
            pq.push(it);
        }
        for(int i=0;i<k;i++){
            score+=pq.top();
            int x=ceil((double)pq.top()/3);
            pq.pop();
            pq.push(x);
        }
        return score;
        
    }
};