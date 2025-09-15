#include <bits/stdc++.h>
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int cnt =0;
        unordered_map<char,int> mpp;
        for(auto it:brokenLetters){
            mpp[it]++;
        }
        int i=0;
        int total_words=count(text.begin(),text.end(),' ')+1;
        while(i<text.size()){
            if(text[i]!='.' && mpp.count(text[i])){
                cnt++;
                cout << i;
                while(i<text.size() && text[i]!= ' '){
                    i++;
                   
                }

            }
            else{
                i++;
            }
        }
      
        return total_words-cnt;
        
    }
};