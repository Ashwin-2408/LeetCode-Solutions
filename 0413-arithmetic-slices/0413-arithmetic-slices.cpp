class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        if(arr.size()<3){
            return 0;
        }
        int i=0;
        int j=1;
        int curr_diff=(arr[j]-arr[i]);
        int ans=0;
        while(j<arr.size()){
            if(j!=arr.size() && (arr[j]-arr[j-1])==curr_diff){
                j++;
            }
            else{
                if(j-i+1>=3){
                    int length=j-i;
                    ans+=((length-2)*(length-1))/2;
                    i=j-1;
                    if(j!=arr.size()){
                    curr_diff=abs(arr[j]-arr[j-1]);
                    }
                    
                }
                j++;
            }
        }
        if(j-i>=3){
            int length=j-i;
            ans+=((length-2)*(length-1))/2;

        }
        

        return ans;

        
    }
};