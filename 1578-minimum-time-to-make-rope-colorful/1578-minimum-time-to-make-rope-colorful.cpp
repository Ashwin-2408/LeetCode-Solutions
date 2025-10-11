class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        char alpha=colors[0];
        int maximum_value=neededTime[0];
        int curr_sum=neededTime[0];
        for(int i=1;i<colors.size();i++){
            if(colors[i]==alpha){
                maximum_value=max(neededTime[i],maximum_value);
                curr_sum+=neededTime[i];

            }
            else{
                
                ans+=(curr_sum-maximum_value);
                
                alpha=colors[i];
                curr_sum=neededTime[i];
                maximum_value=neededTime[i];
            }
            cout << ans;
        }
        
        ans+=(curr_sum-maximum_value);
            
        return ans;
        
    }
};