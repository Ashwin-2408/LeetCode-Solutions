class Solution {
public:
    static bool comparator(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    }
    int minSwaps(vector<int>& nums) {
        vector<pair<int, int>> arr;
        for (auto it : nums) {
            int dum = it;
            int sum = 0;
            while (it > 0) {
                sum += it % 10;
                it /= 10;
            }
            arr.push_back({sum, dum});
        }
        sort(arr.begin(), arr.end(), comparator);
        
        int swaps = 0;
        unordered_map<int, int> mpp;
        for (int i = 0; i < arr.size(); i++) {
            mpp[arr[i].second] = i;
        }
        vector<int> pos(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            pos[i] = mpp[nums[i]];
        }
        vector<bool> visited(arr.size(), false);
        for (int i = 0; i < arr.size(); i++) {
            if (visited[i] || pos[i] == i)
                continue;

            int cycle_size = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = mpp[nums[j]];
                cycle_size++;
            }

            if (cycle_size > 1){
                swaps += (cycle_size - 1);
            }
        }
        return swaps;
    }
};