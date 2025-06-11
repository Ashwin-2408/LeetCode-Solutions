class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maximum=0;
        int l=0;
        int r=0;
        unordered_set<char> st;
        
        while(r<s.size()){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                int length=r-l+1;
                maximum=max(maximum,length);
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