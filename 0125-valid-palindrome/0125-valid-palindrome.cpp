class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove(s.begin(),s.end(),' '),s.end());
        string processed="";
        for(auto it: s){
            if(isalnum(it)){
                processed+=tolower(it);
            }
        }
        int i=0;
        int j=processed.size()-1;
        while(i<=j){
            if(processed[i]!=processed[j]){
                return false;
            }
            i++;
            j--;
        
        }
        return true;
        
    }
};