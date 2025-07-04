class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty_bottles=numBottles;
        int ans=numBottles;
        while(empty_bottles>=numExchange){
            ans+=empty_bottles/numExchange;
            empty_bottles=empty_bottles%numExchange;
            numExchange++;

        }
        return ans;
        
    }
};