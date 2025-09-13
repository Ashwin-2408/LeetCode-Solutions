class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> mpp;
        vector<string> ans;
        for(auto it:cpdomains){
            string temp="";
            int i=0;
            while(it[i]!=' '){
                temp.push_back(it[i]);
                i++;

            }
            int val=stoi(temp);
            
            string remaining=it.substr(i+1);
            mpp[remaining]+=val;
            string parent=remaining.substr(remaining.find('.')+1);
            mpp[parent]+=val;
            if(parent.find('.')!=string::npos){
                string org=parent.substr(parent.find('.')+1);
                mpp[org]+=val;
            }


        }
        string temp_ans="";
        for(auto it: mpp){
            
            temp_ans=to_string(it.second)+" "+it.first;
            ans.push_back(temp_ans);
        }
        
        return ans;
    }
};