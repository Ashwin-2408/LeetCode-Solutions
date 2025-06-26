class Solution {
public:
    int countOfSubstrings(string word, int k) {
       int count = 0;
        int n = word.size();
        
        for (int i = 0; i < n; i++) {
            int consonants = 0;
            unordered_map<char, int> vowelMap;
            unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
            
            for (int j = i; j < n; j++) {
                char ch = word[j];
                
                if (vowels.count(ch)) {
                    vowelMap[ch]++;
                } else {
                    consonants++;
                }

                if (vowelMap.size() == 5 && consonants == k) {
                    count++;
                }
            }
        }
        return count;
    }
    
};