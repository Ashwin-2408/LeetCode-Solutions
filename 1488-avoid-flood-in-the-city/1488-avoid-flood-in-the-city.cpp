class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_map<int,int> mpp;
        unordered_map<int,queue<int>> upcoming;
        for(int i=0;i<rains.size();i++){
            upcoming[rains[i]].push(i);
        }
        vector<int> ans;
        for(int i=0;i<rains.size();i++){
            if(rains[i]>0){
                if(mpp.count(rains[i])){
                    return {};
                }
                mpp[rains[i]]++;
                 upcoming[rains[i]].pop();
                if(!upcoming[rains[i]].empty()){
                    pq.push({upcoming[rains[i]].front(),rains[i]});
                }
                ans.push_back(-1);

            }
            else{
                if(!pq.empty()){
                    auto it=pq.top();
                    pq.pop();
                    mpp.erase(it.second);
                    ans.push_back(it.second);
                }
                else{
                    ans.push_back(1);
                }
            }
           
            

        }
        return ans;



        
    }
};