class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int left_m=0;
        if(left.size()>0){
            left_m=*max_element(left.begin(),left.end());
        }
        int right_m=0;
        if(right.size()>0){
            right_m=*min_element(right.begin(),right.end());

        }
        return max(left_m-0,n-right_m);
        
    }
};