class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l=0;
        int r=0;
        int maximum=0;
        while(r<s.size()){
            
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                maximum=max(maximum,r-l+1);
                r++;

            }
            else{
                st.erase(s[l]);
                l++;

            }
            
        }
        
        return maximum;
    }
};