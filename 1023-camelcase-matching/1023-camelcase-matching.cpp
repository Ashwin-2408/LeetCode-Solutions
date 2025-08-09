class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            int j=0;
            int k=0;
            while(j<queries[i].size()){
                if(k==pattern.size()){
                    ans[i]=true;
                    break;
                }
                if(queries[i][j]!=pattern[k] && isupper(queries[i][j])){
                    ans[i]=false;
                    break;
                }
                if(queries[i][j]==pattern[k]){
                    k++;
                }
                
                j++;
            }
            if(k==pattern.size()){
                ans[i]=true;
            }
            while(j<queries[i].size()){
                if(isupper(queries[i][j])){
                    ans[i]=false;
                    break;
                }
                j++;
            }
        }
        return ans;
        
    }
};