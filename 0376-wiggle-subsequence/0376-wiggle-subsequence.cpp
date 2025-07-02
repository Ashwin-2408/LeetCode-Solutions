class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int prev_diff = 0;
        int i;

        for (i = 1; i < nums.size() && prev_diff == 0; ++i) {
            prev_diff = (nums[i] - nums[i - 1] > 0)   ? 1
                        : (nums[i] - nums[i - 1]) < 0 ? -1
                                                      : 0;
        }
        cout << prev_diff;
        int count = 2;
        if(prev_diff==0){
            count=1;
        }
        for (i; i < nums.size(); i++) {
            if ((nums[i] - nums[i - 1]) < 0) {
                if (prev_diff == 1) {
                    count++;
                    prev_diff = -1;
                }
            } else if ((nums[i] - nums[i - 1]) > 0) {
                if (prev_diff == -1) {
                    count++;
                    prev_diff = 1;
                }
            } else {
                continue;
            }
        }
        return count;
    }
};