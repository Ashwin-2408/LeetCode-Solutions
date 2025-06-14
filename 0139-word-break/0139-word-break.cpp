class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.size() + 1; i++) {
            for (int j = 0; j <= i; j++) {

                string str = s.substr(j, i - j);
                if (dp[j] && (find(wordDict.begin(), wordDict.end(), str) !=
                              wordDict.end())) {
                    dp[i] = true;
                    break;
                }
            }
            
        }
        return dp[s.size()];
    }
};