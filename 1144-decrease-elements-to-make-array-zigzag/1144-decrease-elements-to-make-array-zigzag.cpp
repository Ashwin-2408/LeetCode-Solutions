class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int even=0;
        vector<int> dum1=nums;
        for(int i=0;i<dum1.size();i+=2){
            if(i-1>=0){
                if(dum1[i-1]>=dum1[i]){
                    even+=(dum1[i-1]-dum1[i]+1);
                    dum1[i-1]-=(dum1[i-1]-dum1[i]+1);
                    cout << i;
                }
            }
            if(i+1<dum1.size()){
                if(dum1[i+1]>=dum1[i]){
                    even+=(dum1[i+1]-dum1[i]+1);
                    dum1[i+1]-=(dum1[i+1]-dum1[i]+1);
                    cout << i;
                    
                }
                
            }
            cout << endl;

        }
        int odd=0;
        for(int i=1;i<nums.size();i+=2){
            if(i-1>=0){
                if(nums[i-1]>=nums[i]){
                    odd+=(nums[i-1]-nums[i]+1);
                    nums[i-1]-=(nums[i-1]-nums[i]+1);
                    cout << i;
                }
               
            }
            if(i+1<nums.size()){
                if(nums[i+1]>=nums[i]){
                    odd+=(nums[i+1]-nums[i]+1);
                    nums[i+1]-=(nums[i+1]-nums[i]+1);
                    cout << i;
                }
            }
            cout << endl;

        }
        return min(odd,even);

        
    }
};