class Solution {
public:
    int possibleStringCount(string word) {
        char c=word[0];
        int ans=1;
        int length=1;
        for(int i=1;i<word.size();i++){
            if(word[i]==c){
                length++;

            }
            else{
                ans+=length-1;
                c=word[i];
                length=1;
            }
        }
        ans+=length-1;
        return ans;
        
    }
};