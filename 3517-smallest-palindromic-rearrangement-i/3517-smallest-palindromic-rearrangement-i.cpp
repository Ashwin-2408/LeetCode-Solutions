class Solution {
public:
    string smallestPalindrome(string s) {
        string left="";
        string right="";
        vector<int> alpha(26,0);
        for(auto it:s){
            alpha[it-'a']++;
        }
        char mid=' ';
        for(int i=0;i<26;i++){
            if(alpha[i]!=0){
                char c=i+'a';
                int half=alpha[i]/2;
                left.append(half,c);
                if(alpha[i]%2==1){
                    mid=c;
                    
                }

            }

                
        }
        right=left;
        reverse(right.begin(),right.end());
       
       if(mid!=' '){
        
        return left+mid+right;
       }
       return left+right;
        
    }
};