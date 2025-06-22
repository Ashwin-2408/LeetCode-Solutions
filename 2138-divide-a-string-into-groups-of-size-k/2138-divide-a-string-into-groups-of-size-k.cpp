class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int complete_partitions=s.size()/k;
        vector<string> ans;
        string temp="";
        for(int i=0;i<complete_partitions*k;i++){
            temp+=s[i];
            if(temp.size()==k){
                ans.push_back(temp);
                temp="";
            }

        }
        if(complete_partitions*k==s.size()){
            return ans;
        }
        for(int i=complete_partitions*k;i<s.size();i++){
            temp+=s[i];

        }
        while(temp.size()!=k){
            temp+=fill;
        }
        ans.push_back(temp);
        return ans;
        
    }
};