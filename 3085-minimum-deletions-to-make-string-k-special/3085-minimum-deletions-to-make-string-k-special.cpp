class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> alpha(26, 0);
        for (auto it : word) {
            alpha[it - 'a']++;
        }
        vector<int> nums;
        for (auto it : alpha) {
            if (it != 0) {
                nums.push_back(it);
            }
        }
        sort(nums.begin(), nums.end());
        int minimum = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int base = nums[i];
            int temp = 0;

            for (int j = 0; j < i; ++j) {
                temp += nums[j];
            }

            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] > base + k) {
                    temp += nums[j] - (base + k);
                }
            }

            minimum = min(temp, minimum);
        }
        return minimum;
    }
};