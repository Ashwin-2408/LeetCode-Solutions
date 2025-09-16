class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size()/3;
        priority_queue<int> q;
        for(auto it:piles){
            q.push(it);
        }
        int ans=0;
        while(q.size()>n){
            q.pop();
            ans+=q.top();
            q.pop();
            
        }
        return ans;
        
    }
};