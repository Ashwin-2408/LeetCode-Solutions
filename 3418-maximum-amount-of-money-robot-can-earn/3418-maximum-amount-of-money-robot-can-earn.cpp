class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        const int NEG_INF = -1e9;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, NEG_INF)));

        for (int k = 0; k < 3; ++k) {
            if (coins[0][0] >= 0) {
                dp[0][0][k] = coins[0][0];
            } else if (k > 0) {
                dp[0][0][k] = 0;
            } else {
                dp[0][0][k] = coins[0][0];
            }
        }

        for (int j = 1; j < m; ++j) {
            for (int k = 0; k < 3; ++k) {
                int val = coins[0][j];
                if (val >= 0 && dp[0][j-1][k] != NEG_INF) {
                    dp[0][j][k] = dp[0][j-1][k] + val;
                } else {
                    if (k > 0 && dp[0][j-1][k-1] != NEG_INF)
                        dp[0][j][k] = max(dp[0][j][k], dp[0][j-1][k-1]);
                    if (dp[0][j-1][k] != NEG_INF)
                        dp[0][j][k] = max(dp[0][j][k], dp[0][j-1][k] + val);
                }
            }
        }

        for (int i = 1; i < n; ++i) {
            for (int k = 0; k < 3; ++k) {
                int val = coins[i][0];
                if (val >= 0 && dp[i-1][0][k] != NEG_INF) {
                    dp[i][0][k] = dp[i-1][0][k] + val;
                } else {
                    if (k > 0 && dp[i-1][0][k-1] != NEG_INF)
                        dp[i][0][k] = max(dp[i][0][k], dp[i-1][0][k-1]);
                    if (dp[i-1][0][k] != NEG_INF)
                        dp[i][0][k] = max(dp[i][0][k], dp[i-1][0][k] + val);
                }
            }
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                for (int k = 0; k < 3; ++k) {
                    int val = coins[i][j];
                    if (val >= 0) {
                        if (dp[i-1][j][k] != NEG_INF)
                            dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + val);
                        if (dp[i][j-1][k] != NEG_INF)
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k] + val);
                    } else {
                        if (k > 0) {
                            if (dp[i-1][j][k-1] != NEG_INF)
                                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1]);
                            if (dp[i][j-1][k-1] != NEG_INF)
                                dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1]);
                        }
                        if (dp[i-1][j][k] != NEG_INF)
                            dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + val);
                        if (dp[i][j-1][k] != NEG_INF)
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k] + val);
                    }
                }
            }
        }

        return max({dp[n - 1][m - 1][0], dp[n - 1][m - 1][1], dp[n - 1][m - 1][2]});
    }
};
