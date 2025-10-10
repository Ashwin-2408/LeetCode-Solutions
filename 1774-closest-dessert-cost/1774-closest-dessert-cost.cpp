class Solution {
public:
    int closest=INT_MAX;
    int ans=INT_MAX;
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        
        for(int i=0;i<baseCosts.size();i++){
            solve(toppingCosts,0,baseCosts[i],target);
        }
        return ans;

        
    }
    void  solve(vector<int>& toppingCosts,int i,int cost,int target){
        if((abs(target-cost)<closest)){
            ans=cost;
            closest=abs(target-cost);
        }
        if((abs(target-cost)<=closest)){
            ans=min(ans,cost);
            
        }
        
        if(i>=toppingCosts.size()){
            return ;

        }
        solve(toppingCosts,i+1,cost,target);
        solve(toppingCosts,i+1,cost+toppingCosts[i],target);
        solve(toppingCosts,i+1,cost+toppingCosts[i]*2,target);

    }
};