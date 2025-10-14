class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n =nums.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        prefix[0]=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                prefix[i]=prefix[i-1]+1;
            }
            else{
                prefix[i]=1;
            }
        }
        suffix[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                suffix[i]=suffix[i+1]+1;
            }
            else{
                suffix[i]=1;
            }
        }
        int max_ans=0;
        for(int i=1;i<n;i++){
            int longest=min(prefix[i-1],suffix[i]);
            max_ans=max(longest,max_ans);
        }
        return max_ans;
        
    }
};