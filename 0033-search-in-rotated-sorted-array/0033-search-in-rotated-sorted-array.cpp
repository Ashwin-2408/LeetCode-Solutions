class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = nums[0];
        int right = nums[nums.size() - 1];

        if (left > right) {
            int change = -1;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > nums[i + 1]) {
                    change = i;
                    break;
                }
            }
            if (target >= left) {
                left = 0;
                right = change;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] == target) {
                        return mid;
                    } else if (nums[mid] > target) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }

            } else {
                right = nums.size() - 1;
                left = change + 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] == target) {
                        return mid;
                    } else if (nums[mid] > target) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            }
        } else {
            left=0;
            right=nums.size()-1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            
        }
        return -1;
    }
};