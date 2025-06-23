class Solution {
public:
    int maximum=0;
    int longestPalindrome(string s, string t) {
        
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                string sub_s=s.substr(i,j-i+1);
                if(check(sub_s)){
                            maximum=max(maximum,(int)sub_s.size());
                        }
                
                for(int k=0;k<t.size();k++){
                    for(int l=k;l<t.size();l++){
                        string sub_t =t.substr(k,l-k+1);
                        if(check(sub_t)){
                            maximum=max(maximum,(int)sub_t.size());
                        }
                        string curr=sub_s+sub_t;
                        if(check(curr)){
                            maximum=max(maximum,(int)curr.size());
                        }

                    }

                }
            }
        }
        return maximum;


        
    }
    
    bool check(string s){
        string t=s;
        reverse(t.begin(),t.end());
        return s==t;

    }
};