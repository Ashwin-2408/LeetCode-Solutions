class Solution {
public:
    int total=0;
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        backtrack(nums,0,k,freq);
        return total;
        
    }
    void backtrack(vector<int>& nums,int index,int k,unordered_map<int,int>& freq){
        if(index==nums.size()){
            if(freq.size()!=0){
                total++;
            }
            return;
        }

        backtrack(nums,index+1,k,freq);
        if(freq.find(nums[index]-k)==freq.end() && freq.find(nums[index]+k)==freq.end()){
            freq[nums[index]]++;
            backtrack(nums,index+1,k,freq);
            freq[nums[index]]--;
        if(freq[nums[index]]==0){
            freq.erase(nums[index]);
        }
        }
        
    }
};