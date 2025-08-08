class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        
        int max_parcel=INT_MIN;
        int i=0;
        int count=0;
        while(i<weight.size()){
            if(max_parcel==INT_MIN){
                max_parcel=weight[i];
            }
            else{
                if(weight[i]<max_parcel){
                    count++;
                    max_parcel=INT_MIN;
                }
                else{
                    max_parcel=max(max_parcel,weight[i]);
                }
            }
            i++;
        }
        return count;
        
    }
};