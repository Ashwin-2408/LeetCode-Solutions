class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> results;
        recurse(n,"",results);
        if(k>results.size()){
            return "";
        }
        return results[k-1];

        
    }
    void recurse(int n,string s,vector<string>& results){
        if(n==0){
            results.push_back(s);
            return;
        }
        int last=s.size()-1;
        if(s.size()==0){
            recurse(n-1,s+'a',results);
            recurse(n-1,s+'b',results);
            recurse(n-1,s+'c',results);

        }
        else if(s[last]=='a'){
            recurse(n-1,s+'b',results);
            recurse(n-1,s+'c',results);

        }
        else if(s[last]=='b'){
            recurse(n-1,s+'a',results);
            recurse(n-1,s+'c',results);

        }
        else{
            recurse(n-1,s+'a',results);
            recurse(n-1,s+'b',results);

        }
        
        
    }
};