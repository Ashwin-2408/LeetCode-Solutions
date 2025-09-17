class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        priority_queue<pair<int, char>> pq;
        if(a>0){
        pq.push({a, 'a'});
        }

        if(b>0){
        pq.push({b, 'b'});
        }
        if(c>0){
        pq.push({c, 'c'});
        }
        while (!pq.empty()) {
            while (!pq.empty()) {
                if (ans.size() == 0 || ans[ans.size() - 1] != pq.top().second) {
                    auto it = pq.top();
                    int val = min(2, it.first);
                    for (int i = 1; i <= val; i++) {
                        ans.push_back(it.second);
                    }
                    pq.pop();
                    if(it.first-val>0){
                    pq.push({it.first - val, it.second});
                    }

                } else {
                    if (pq.size() == 1) {
                        
                        auto it = pq.top();
                        if(it.second==ans[ans.size()-1]){
                            pq.pop();
                            break;
                        }
                        int val = min(2, it.first);
                        for (int i = 1; i <= val; i++) {
                            ans.push_back(it.second);

                        }
                        cout <<1;
                        pq.pop();
                    } else {
                        auto it1 = pq.top();
                        pq.pop();
                        auto it2 = pq.top();
                        pq.pop();
                        ans.push_back(it2.second);
                        pq.push({it1.first, it1.second});
                        if(it2.first-1>0){
                        pq.push({it2.first - 1, it2.second});
                        }
                    }
                }
            }
        }
        return ans;
    }
};