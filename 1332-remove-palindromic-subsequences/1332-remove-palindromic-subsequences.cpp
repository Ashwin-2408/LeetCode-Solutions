class Solution {
public:
    bool is_palindrome(string s){
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(is_palindrome(s)){
            return 1;
        }
        else{
            return 2;
        }
        
        
        
    }
};