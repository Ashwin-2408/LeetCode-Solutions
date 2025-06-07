

class Solution {
public:
    string clearStars(string s) {
        auto cmp=[](const pair<char,int> &a , const pair <char,int> &b){
            if(a.first==b.first){
                return a.second< b.second;
            }
            return a.first>b.first;
        };
        vector<int> popped_index;
        priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(cmp)> pq(cmp);
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                if(!pq.empty()){
                 
                    int index=pq.top().second;
                    pq.pop();
                    popped_index.push_back(index);
                }
            }
            else{
                pq.push({s[i],i});
            }
        }
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                continue;
            }
            if(find(popped_index.begin(),popped_index.end(),i)!=popped_index.end()){
                continue;
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};