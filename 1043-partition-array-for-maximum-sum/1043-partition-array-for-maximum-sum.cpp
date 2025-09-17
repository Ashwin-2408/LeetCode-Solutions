class Solution {
public:
    vector<int> dp;
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size(),-1);
        return recurse(arr,0,k);
        

        
    }
    int recurse(vector<int>&arr ,int i , int k){
        if(i>=arr.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int maximum=INT_MIN;
        int len=0;
        int max_val=INT_MIN;
        for(int j=i;j<min(int(arr.size()),i+k);j++){
            len++;
            max_val=max(arr[j],max_val);
            maximum=max(maximum,(len*max_val)+recurse(arr,j+1,k));
        }
        return dp[i]=maximum;
    }
};