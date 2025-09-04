class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long min_sum_1=0;
        long long min_sum_2=0;
        bool zero_1=false;
        bool zero_2=false;
        for(auto it: nums1){
            if(it==0){
                min_sum_1++;
                zero_1=true;
            }
            else{
                min_sum_1+=it;
            }
        }
        for(auto it: nums2){
            if(it==0){
                min_sum_2++;
                zero_2=true;
            }
            else{
                min_sum_2+=it;
            }
        }
        if(min_sum_1==min_sum_2){
            return min_sum_1;
        }
        else if(min_sum_1> min_sum_2){
            if(zero_2){
                return min_sum_1;
            }
            else{
                return -1;
            }
        }
        else{
            if(zero_1){
                return  min_sum_2;
            }
            else{
                return -1;
            }
        }
        
    }
};