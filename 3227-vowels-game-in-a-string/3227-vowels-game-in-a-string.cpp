class Solution {
public:
    bool doesAliceWin(string s) {
        int vowel_count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                vowel_count++;
            }
        }
        if(vowel_count==0){
            return false;
        }
        if(vowel_count%2==1){
            return true;
        }
        else{
            return true;

        }
    }
};