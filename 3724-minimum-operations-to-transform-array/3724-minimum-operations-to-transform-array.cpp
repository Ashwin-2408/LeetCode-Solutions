class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int last=nums2.back();
        long long ans=0;
        int min_append=INT_MAX;
        cout << last;
        for(int i=0;i<nums1.size();i++){
            if(min_append!=0){
                int minimum=min(nums1[i],nums2[i]);
                int maximum=max(nums1[i],nums2[i]);
                
                if(last>= minimum && last<=maximum){
                    
                    min_append=0;
                }
                min_append=min(min_append,abs(nums1[i]-last));
                
                min_append=min(min_append,abs(nums2[i]-last));

            }
            ans+=abs(nums1[i]-nums2[i]);
            




        }
        cout << min_append;
        ans+=(1+min_append);
        return ans;
        
    }
};