class Solution {
public:
    string resultingString(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(!st.empty() &&((st.top()%26)== (s[i]+1)%26 || (st.top()+1)%26==(s[i]%26) )){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();

        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};