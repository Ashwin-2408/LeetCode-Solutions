class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()){
            return "";
        }
        unordered_map<char,int> original,check;
        for(auto it: t){
            original[it]++;
        }
        int required=original.size();
        int valid=0;
        int l=0;
        int r=0;
        int final_l=0;
        int final_r=INT_MAX-1;
        while(r<s.size()){
            if(original.count(s[r])==1){
                check[s[r]]++;
                if(original[s[r]]==check[s[r]]){
                    valid++;
                }

            }
            
            
            while(valid==required && l<=r){
                if(r-l+1 < final_r-final_l+1){
                    final_l=l;
                    final_r=r;
                }
                if(check.count(s[l])==1){
                    if(original[s[l]]==check[s[l]]){
                        valid--;
                    }
                    check[s[l]]--;
                    
                }
                l++;
            }
            r++;
        }
        string ans="";
        if(final_r==INT_MAX-1){
            return ans;
        }
        for(int i=final_l;i<=final_r;i++){
            ans.push_back(s[i]);
        }    
        return ans;    
        
    }
};