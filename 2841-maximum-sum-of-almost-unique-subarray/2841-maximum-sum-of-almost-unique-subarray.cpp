class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int,int> s;
        
        int i=0;
        int j=0;
        long long ans=0;
        while(j<nums.size()){
            s[nums[j]]++;
            
            
            if(j-i+1>k){
                s[nums[i]]--;
                if(s[nums[i]]==0){
                    s.erase(nums[i]);
                }
                
                i++;
            }
            if(j-i+1==k && s.size()>=m){
                ans=max(ans,(long long)accumulate(nums.begin()+i,nums.begin()+j+1,0));

            }
            j++;
            

        }
        return ans;
        
    }
};