class Solution {
public:
    vector<vector<int>> dp;
    int minSideJumps(vector<int>& obstacles) {
        dp.resize(obstacles.size() + 1, vector<int>(4, -1));
        return recurse(obstacles, 0, 2);
    }
    int recurse(vector<int>& obstacles, int i, int lane) {
        if (i == obstacles.size() - 1) {

            return 0;
        }
        if (dp[i][lane] != -1) {
            return dp[i][lane];
        }
        int res = INT_MAX;
        if (obstacles[i + 1] != lane) {
            res = min(res, recurse(obstacles, i + 1, lane));
        } else {
            for (int k = 1; k <= 3; k++) {
                if (k != lane && obstacles[i] != k) {
                    res = min(res, 1 + recurse(obstacles, i, k));
                }
            }
        }
        return dp[i][lane] = res;
    }
};