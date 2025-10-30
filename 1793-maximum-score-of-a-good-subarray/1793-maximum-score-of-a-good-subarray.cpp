class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> nse(n,0);
        vector<int> pse(n,0);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[i]<=nums[s.top()]){
                s.pop();
            }
            if(s.empty()){
                pse[i]=-1;
            }
            else{
                pse[i]=s.top();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[i]<=nums[s.top()]){
                s.pop();
            }
            if(s.empty()){
                nse[i]=n;
            }
            else{
                nse[i]=s.top();
            }
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(pse[i]+1<=k && nse[i]-1>=k){
                cout << i << endl;
                ans=max(ans,nums[i]*(nse[i]-pse[i]-1));
                cout << ans << " ";
            }
        }
        return ans;
        
    }
};