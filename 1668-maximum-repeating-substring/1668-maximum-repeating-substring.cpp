class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int k=0;
        string dup_word=word;
        while(dup_word.size()<=sequence.size()){
            if(sequence.find(dup_word)!=string::npos){
                k++;
                dup_word+=word;
            }
            else{
                break;
            }
        }
        return k;
        
    }
};