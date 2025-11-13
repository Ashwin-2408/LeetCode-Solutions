class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool breakable=true;
        for(int i=0;i<s1.size();i++){
            if(s1[i]<s2[i]){
                breakable=false;
                break;
            }
        }
        if(breakable){
            return true;
        }
        breakable=true;
         for(int i=0;i<s1.size();i++){
            if(s1[i]>s2[i]){
                breakable=false;
                break;
            }
        }
        return breakable;
    }
};