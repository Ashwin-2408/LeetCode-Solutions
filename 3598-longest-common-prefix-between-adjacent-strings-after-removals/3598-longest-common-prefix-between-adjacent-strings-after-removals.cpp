class Solution {
public:
    int compute_prefix(string&a ,string&b){
        int i=0;
        int j=0;
        int count=0;
        while(i<a.size() && j<b.size()){
            if(a[i]!=b[j]){
                return count;
            }
            else{
                count++;
            }
            i++;
            j++;
            
        }
        return count;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        if(words.size()==1){
            return {0};
            
        }
        if(words.size()==2){
            return {0,0}; 
            
        }

        vector<int> adjacent_prefix(words.size()-1,0);
        for(int i=0;i<words.size()-1;i++){
            adjacent_prefix[i]=compute_prefix(words[i],words[i+1]);
        }
        vector<int> prefix(words.size()-1,0);
        vector<int> suffix(words.size()-1,0);
        prefix[0]=adjacent_prefix[0];
        for(int i=1;i<words.size()-1;i++){
            prefix[i]=max(prefix[i-1],adjacent_prefix[i]);
            
        }
        suffix[words.size()-2]=adjacent_prefix[words.size()-2];
        for(int i=words.size()-3;i>=0;i--){
            suffix[i]=max(suffix[i+1],adjacent_prefix[i]);
        }
        vector<int> ans(words.size(),0);
        for(int i=0;i<words.size();i++){
            if(words.size()<=2){
                if(i==0 && words.size()>1){
                    ans[i]=0;
                }
                else if(i==1 && words.size()>1){
                    ans[i]=0;
                }
                continue;
            }
            if(i==0){
                ans[i]=suffix[1];
                
            }
            else if(i==words.size()-1){
                if(words.size()>=3){
                    ans[i]=prefix[words.size()-3];
                    
                }
                else{
                    ans[i]=0;
                }
                
                
            }
            else{
                int left=0;
                int right=0;
                if(i-2>=0){
                 left=prefix[i-2];
                }
                if(i+1<words.size()-1){
                 right=suffix[i+1];
                }
                int new_compute=compute_prefix(words[i-1],words[i+1]);
                ans[i]=max({right,left,new_compute});
            }
        }
        return ans;
        
    }
};