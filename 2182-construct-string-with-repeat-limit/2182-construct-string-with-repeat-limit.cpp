class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char,int>,vector<pair<char,int>>> pq;
        for(int i=0;i<26;i++){
            char c='a'+i;
            int cnt=count(s.begin(),s.end(),c);
            if(cnt>0){
                pq.push({c,cnt});
            }
        }
        string ans="";
        bool end=false;
        while(!pq.empty()){
            auto [c,count]=pq.top();
            if(count>repeatLimit){
                string sub(repeatLimit,c);
                ans+=sub;
                pq.pop();
                if(pq.empty()){
                    break;
                    end=true;
                }
                auto [next_char,count1]=pq.top();
                ans+=next_char;
                pq.pop();
                if(count1-1>0){
                    pq.push({next_char,count1-1});

                }
                
                pq.push({c,count-repeatLimit});


            }
            else{
                string sub(count,c);
                ans+=sub;
                pq.pop();

            }
            if(end){
                break;
            }
            
        }
        return ans;
        
    }
};