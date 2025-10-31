class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int max_len_odd = 1;
        int count = 1;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i+1]) {
                if (i % 2 == 1) {
                    count++;

                } else {
                    count = 1;
                }
            } else if (arr[i]<arr[i+1]){
                if (i % 2 == 0) {
                    count++;
                } else {
                    count = 1;
                }

            } else {
                count = 1;
            }
            max_len_odd = max(max_len_odd, count);
        }
        int max_len_even=1;
        count=1;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] < arr[i+1]) {
                if (i % 2 == 1) {
                    count++;

                } else {
                    count = 1;
                }
            } else if (arr[i]>arr[i+1]){
                if (i % 2 == 0) {
                    count++;
                } else {
                    count = 1;
                }

            } else {
                count = 1;
            }
            max_len_even = max(max_len_even, count);
        }
        return max(max_len_even,max_len_odd);
    }
};