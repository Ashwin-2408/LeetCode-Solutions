class Solution {
public:
    int maxVowels(string s, int k) {
        int vowels=0;
        int ans=0;
        int i=0;
        int j=0;
        while(j<s.size()){
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                vowels++;

            }
            int length=j-i+1;
            if(length>k){
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                    vowels--;
                    
                }
                i++;

            }
        
            ans=max(ans,vowels);
            j++;

        }
        return ans;
    }
};