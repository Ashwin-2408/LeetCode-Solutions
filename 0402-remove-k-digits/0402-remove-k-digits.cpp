class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        s.push(num[0]);
        for(int i=1;i<num.size();i++){
            while(k>0 && !s.empty() && s.top()>num[i]){
                s.pop();
                k--;
            }
            s.push(num[i]);

        }
        while(k>0){
            s.pop();
            k--;
        }
        string ans="";
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();

        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size() && ans[i]=='0'){
            i++;
        }
        ans=ans.substr(i);
        
        if(ans==""){
            return "0";
        }
        return ans;
    }
};