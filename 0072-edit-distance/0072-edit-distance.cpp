class Solution {
public:
    int minDistance(string word1, string word2) {
        return min_edit_distance(word1, word2, 0, 0);
    }
    int min_edit_distance(string word1, string word2, int i, int j) {
        if (i == word1.size())
            return word2.size() - j;
        if (j == word2.size())
            return word1.size() - i;
        if (word1[i] == word2[j]) {
            return min_edit_distance(word1, word2, i + 1, j + 1);
        } else {
            return 1 + min(min_edit_distance(word1, word2, i, j + 1),
                           min(min_edit_distance(word1, word2, i + 1, j),
                               min_edit_distance(word1, word2, i + 1, j + 1)));
        }
    }
};