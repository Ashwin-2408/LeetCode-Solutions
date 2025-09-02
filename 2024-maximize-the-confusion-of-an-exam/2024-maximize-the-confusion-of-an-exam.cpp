class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i=0;
        int j=0;
        int operations=0;
        int ans=0;
        while(j<answerKey.size()){
            if(answerKey[j]=='F'){
                operations++;
            }
            while(operations>k){
                if(answerKey[i]=='F'){
                    operations--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;

        }
        operations=0;
        i=0;
        j=0;
        while(j<answerKey.size()){
            if(answerKey[j]=='T'){
                operations++;
            }
            while(operations>k){
                if(answerKey[i]=='T'){
                    operations--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;

        }
        return ans;
        
    }
};