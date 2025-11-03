class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_cost=accumulate(gas.begin(),gas.end(),0);
        int gas_amount=accumulate(cost.begin(),cost.end(),0);
        if(gas_amount>gas_cost){
            return -1;
        }
        int current_gas=0;
        int start=0;
        for(int i=0;i<gas.size();i++){
            current_gas+=(gas[i]-cost[i]);
            if(current_gas<0){
                current_gas=0;
                start=i+1;
            }
        }
        return start;


        
    }
};