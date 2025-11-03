class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int> mpp;
        for(auto it: s){
            mpp[it]++;
        }
        for(auto it: mpp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            if(ans.size()==0 || pq.top().second!=ans[ans.size()-1]){
                int val=pq.top().first;
                char letter=pq.top().second;
                pq.pop();
                ans.push_back(letter);
                val--;
                if(val>0){
                    pq.push({val,letter});
                }
            }
            else{
                int prev=pq.top().first;
                char prev_letter=pq.top().second;
                pq.pop();
                if(pq.empty()){
                    return "";
                }
                else{
                    int val=pq.top().first;
                    char letter=pq.top().second;
                    pq.pop();
                    ans.push_back(letter);
                    val--;
                    if(val>0){
                        pq.push({val,letter});
                    }

                }
                pq.push({prev,prev_letter});
            }
        }
        return ans;
    
        
    }
};