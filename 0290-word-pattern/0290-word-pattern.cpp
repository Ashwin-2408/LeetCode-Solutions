class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        string word;
        vector<string> words;
        while(iss >> word){
            words.push_back(word);
        }
        map<char,string> mpp;
        map<string,char>mpp1;
        if(pattern.size()!=words.size()){
            return false;
        }
        for(int i=0;i<pattern.size();i++){
            if(mpp.find(pattern[i])==mpp.end()){
                mpp[pattern[i]]=words[i];
            }
            if(mpp1.find(words[i])==mpp1.end()){
                mpp1[words[i]]=pattern[i];
            }
          
            if(words[i]!=mpp[pattern[i]] || pattern[i]!=mpp1[words[i]]){
                    return false;
                }
            
        }
        return true;
        
    }
};