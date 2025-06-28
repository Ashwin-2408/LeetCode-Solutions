class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        vector<int> first(text.size()+1,0);
        first[0]=1;
        if(pattern[0]==pattern[1]){
            first[0]=0;

        }
        
        for(int i=1;i<text.size()+1;i++){
            if(text[i-1]==pattern[0]){
                first[i]=1+first[i-1];
            }
            else{
                first[i]=first[i-1];


            }
        }
        long long count_first=0;
        for(int i=0;i<text.size();i++){
            if(text[i]==pattern[1]){
                count_first+=first[i+1];

            }
        }
        vector<int> last(text.size()+1,0);
        last[text.size()]=1;
        for(int i=text.size()-1;i>=0;i--){
            if(text[i]==pattern[1]){
                last[i]=1+last[i+1];

            }
            else{
                last[i]=last[i+1];
            }
        }
        long long count_last=0;
        for(int i=text.size()-1;i>=0;i--){
            if(text[i]==pattern[0]){
                count_last+=last[i+1];

            }
        }
      
        cout << count_last << count_first;
        return max(count_first,count_last);
        
    }
};