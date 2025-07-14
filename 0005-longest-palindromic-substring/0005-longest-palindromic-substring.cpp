class Solution {
public:
    string longestPalindrome(string s) {
        int max_len=0;
        string ans="";
        for(int i=0;i<s.size();i++){
            int l=i;
            int r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                
                if(r-l+1>max_len){
                    max_len=max(max_len,r-l+1);
                    ans=s.substr(l,r-l+1);
                }
                r++;
                l--;


            }
            l=i;
            r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                
                if(r-l+1>max_len){
                    max_len=max(max_len,r-l+1);
                    ans=s.substr(l,r-l+1);
                }
                r++;
                l--;


            }

        }
        return ans;

        
    }
};