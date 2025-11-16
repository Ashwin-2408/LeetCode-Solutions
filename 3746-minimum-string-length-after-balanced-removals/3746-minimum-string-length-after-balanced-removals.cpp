class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a_count=0;
        int b_count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                if(b_count>0){
                    b_count--;
                }
                else{
                    a_count++;
                }
            }
            else{
                if(a_count>0){
                    a_count--;
                }
                else{
                    b_count++;
                }
            }

        }
        return a_count+b_count;
        
    }
};