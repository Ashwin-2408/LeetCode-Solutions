class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string cur="";
        recurse(s,0,ans,cur);
        return ans;
        
    }
    void recurse(string &s ,int i,vector<string>& ans,string &curr){
        if(s.size()==i){
            ans.push_back(curr);
            return;
        }
        if(!isalpha(s[i])){
            curr.push_back(s[i]);
            recurse(s,i+1,ans,curr);
            curr.pop_back();
        }
        else{
           curr.push_back(toupper(s[i]));
           recurse(s,i+1,ans,curr);
           curr.pop_back();
           curr.push_back(tolower(s[i]));
           recurse(s,i+1,ans,curr);
           curr.pop_back();
        }

    }
};