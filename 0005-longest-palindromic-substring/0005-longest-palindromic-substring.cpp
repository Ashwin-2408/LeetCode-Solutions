class Solution {
public:
    string longestPalindrome(string s) {
        string result="";
        for(int i=0;i<s.size();i++){
            string expanded=expansion(s,i,i);
            if(result.size() <expanded.size() ){
                result=expanded;
            }
            expanded=expansion(s,i,i+1);
            if(result.size() <expanded.size() ){
                result=expanded;
            }


        }
        return result;



        
    }
    string expansion(string s,int i,int j){
        while(i>=0 &&  j<s.size()  && s[i]==s[j]){
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
};