class Solution {
public:
    string sortVowels(string s) {
        vector<int>positions;
        vector<int> vowels (256,0);

        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'|| s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                positions.push_back(i);
                vowels[(int)s[i]]++;
            }

        }
        for(int i=0;i<positions.size();i++){
           for (int i = 0; i < positions.size(); i++) {
    if (vowels['A'] > 0) {
        s[positions[i]] = 'A';
        vowels['A']--;
    }
    else if (vowels['E'] > 0) {
        s[positions[i]] = 'E';
        vowels['E']--;
    }
    else if (vowels['I'] > 0) {
        s[positions[i]] = 'I';
        vowels['I']--;
    }
    else if (vowels['O'] > 0) {
        s[positions[i]] = 'O';
        vowels['O']--;
    }
    else if (vowels['U'] > 0) {
        s[positions[i]] = 'U';
        vowels['U']--;
    }
    else if (vowels['a'] > 0) {
        s[positions[i]] = 'a';
        vowels['a']--;
    }
    else if (vowels['e'] > 0) {
        s[positions[i]] = 'e';
        vowels['e']--;
    }
    else if (vowels['i'] > 0) {
        s[positions[i]] = 'i';
        vowels['i']--;
    }
    else if (vowels['o'] > 0) {
        s[positions[i]] = 'o';
        vowels['o']--;
    }
    else if (vowels['u'] > 0) {
        s[positions[i]] = 'u';
        vowels['u']--;
    }
}

        }
        return s;
        
        
    }
};