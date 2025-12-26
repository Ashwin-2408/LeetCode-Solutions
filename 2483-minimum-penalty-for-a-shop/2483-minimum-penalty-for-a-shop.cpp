class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> suffix_y(n+1,0);
        vector<int> prefix_n(n+1,0);
        for(int i=n-1;i>=0;i--){
            if(customers[i]=='Y'){
                suffix_y[i]=suffix_y[i+1]+1;
            } 
            else{
                suffix_y[i]=suffix_y[i+1];

            }
        }
        for(int i=1;i<n+1;i++){
            if(customers[i-1]=='N'){
                prefix_n[i]=prefix_n[i-1]+1;
            }
            else{
                prefix_n[i]=prefix_n[i-1];

            }

        }
        int minimum=INT_MAX;
        int index=-1;
        for(int i=0;i<=n;i++){
            int value=prefix_n[i]+suffix_y[i];
            if(value<minimum){
                minimum=value;
                index=i;
            }
            

        }
       
    
        return index;
    }
};