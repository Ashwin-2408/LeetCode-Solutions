class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ending(26,0);
        for(int i=0;i<s.size();i++){
            ending[s[i]-'a']=i;
        }
        int final=ending[s[0]-'a'];
        int i=0;
        int break_point=0;
        vector<int> ans;
        while(i<s.size()){
            if(i==final){
                ans.push_back(i-break_point+1);
                break_point=final+1;
                if(i!=s.size()-1){
                    final=max(final,ending[s[i+1]-'a']);
                }
                

            }
            else{
                final=max(final,ending[s[i]-'a']);
                
        
            }
            i++;
        }
       
        return ans;
        
    }
};