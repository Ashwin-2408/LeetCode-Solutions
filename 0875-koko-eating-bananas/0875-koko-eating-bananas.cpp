class Solution {
public:
    bool check(vector<int>& piles,int h,int k){
        int hours_needed=0;
        for(int i=0;i<piles.size();i++){
            if(hours_needed>h){
                return false;
            }
            hours_needed+=ceil((double)piles[i]/k);
        }
        if(hours_needed>h){
                return false;
            }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(piles,h,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;

        
        
    }
};