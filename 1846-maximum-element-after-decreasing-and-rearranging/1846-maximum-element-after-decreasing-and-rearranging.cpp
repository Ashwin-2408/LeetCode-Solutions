class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int greatest = 1;
        for (int i = 0; i < arr.size(); i++) {
            if (i == 0) {
                arr[i] = 1;
            } 
            else {
                if (arr[i] - arr[i - 1] > 1) {
                    arr[i] = arr[i - 1] + 1;
                }
            }
            greatest = max(greatest, arr[i]);
        }
        return greatest;
    }
};