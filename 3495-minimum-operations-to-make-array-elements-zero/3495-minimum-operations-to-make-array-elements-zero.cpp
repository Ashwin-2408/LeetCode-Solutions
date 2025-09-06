class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;

        for (auto it : queries) {
            long long extra = 0;

            int prev = 1;
            int curr = 1;
            for (int i = 1; i < 100; i++) {
                curr = curr * 4;
                if (it[1] < prev) {
                    break;
                }
                if (it[0] > curr) {
                    continue;
                }
                int a = max(it[0], prev);
                int b = min(it[1], curr - 1);
                long long required = (b - a + 1) * i;
                ans += required / 2;
                if (required % 2 == 1) {
                    extra++;
                }

                prev = curr;
            }
            if (extra % 2 == 0) {
                extra = extra / 2;
            } else {
                extra = (extra / 2) + 1;
            }
            ans+=extra;
        }

        return ans;
    }
};