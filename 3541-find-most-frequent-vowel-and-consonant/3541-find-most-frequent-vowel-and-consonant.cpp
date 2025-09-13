class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> freq;
        for(auto it: s){
            freq[it]++;
        }
        vector<int> vowels={'a','e','i','o','u'};
        int vowel=0;
        int consonant=0;
        for(auto it: freq){
            if(find(vowels.begin(),vowels.end(),it.first)!=vowels.end()){
                vowel=max(vowel,it.second);
            }
            else{
                consonant=max(consonant,it.second);
            }
        }
        return  consonant+vowel;
    }
};