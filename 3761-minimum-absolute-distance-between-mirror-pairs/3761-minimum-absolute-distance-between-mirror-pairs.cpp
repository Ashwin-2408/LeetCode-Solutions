class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums){
        unordered_map<string,int> mpp;
        string x=to_string(nums[0]);
        reverse(x.begin(),x.end());
        int num=stoi(x);
        x=to_string(num);
        mpp[x]=0;
        int minimum_ans=INT_MAX;
        for(int i=1;i<nums.size();i++){
            string x=to_string(nums[i]);
            if(mpp.count(x)){
                minimum_ans=min(minimum_ans,i-mpp[x]);
            }
            reverse(x.begin(),x.end());
            int num=stoi(x);
            x=to_string(num);
            mpp[x]=i;



        }
        if(minimum_ans==INT_MAX){
            return -1;
        }
        return minimum_ans;

        
    }
};