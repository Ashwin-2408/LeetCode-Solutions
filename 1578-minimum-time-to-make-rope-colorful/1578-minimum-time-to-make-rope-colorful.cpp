class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost=0;
        int curr_min=neededTime[0];
        int count=1;
        for(int i=1;i<colors.size();i++){
            if(colors[i]!=colors[i-1]){
                if(count>1){
                    cost+=curr_min;

                }
                curr_min=neededTime[i];
                count=1;

            }
            else{
                count++;
                curr_min=min(curr_min,neededTime[i]);
            }

        }
        if(count>1){
            cost+=curr_min;
        }
        return cost;
        
    }
};