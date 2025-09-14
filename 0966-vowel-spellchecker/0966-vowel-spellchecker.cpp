class Solution {
public:
    string remove_vowel(string & s){
        string ans="";
        for(auto it: s){
            if(it=='a'||it=='e'||it=='i'||it=='o'||it=='u'){
                ans.push_back('*');
            }
            else{
                ans.push_back(it);
            }

        }
        return ans;
    }
    string to_lower(string & s){
        string ans="";
        for(auto it: s){
            ans.push_back(tolower(it));
        }
        return ans;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> match(wordlist.begin(),wordlist.end());
        unordered_map<string,string> lower;
        unordered_map<string,string> vowel;
        vector<string> ans;


        for(auto it:wordlist){
            string lower_case=to_lower(it);
            string removed_vowel=remove_vowel(lower_case);
            if(!lower.count(lower_case)){
                lower[lower_case]=it;
            }
            if(!vowel.count(removed_vowel)){
                vowel[removed_vowel]=it;
            }
        }
        for(auto it:queries){
            if(match.count(it)){
                ans.push_back(it);
            }
            else{
                string lower_case=to_lower(it);
                string removed_vowel=remove_vowel(lower_case);
                if(lower.count(lower_case)){
                    ans.push_back(lower[lower_case]);
                }   
                else if(vowel.count(removed_vowel)){
                    ans.push_back(vowel[removed_vowel]);
                }
                else{
                    ans.push_back("");
                }

            }

        }
        return ans;



        
    }
};