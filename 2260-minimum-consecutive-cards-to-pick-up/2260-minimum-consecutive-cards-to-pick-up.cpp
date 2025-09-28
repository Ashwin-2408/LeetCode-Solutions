class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> mpp;
        int i=0;
        int j=0;
        int minimum_card_pickup=INT_MAX;
        while(j<cards.size()){
            if(mpp.count(cards[j])){
                
                minimum_card_pickup=min(minimum_card_pickup,j-mpp[cards[j]]+1);
                mpp[cards[j]]=j;
                
            }
            else{
                mpp[cards[j]]=j;
            }
            j++;
        }
        return minimum_card_pickup==INT_MAX ?-1 : minimum_card_pickup;
    }
};