class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=0;
        int emptyBottles=0;
        while(numBottles!=0 || emptyBottles>=numExchange){
            ans+=numBottles;
            emptyBottles+=numBottles;
            numBottles-=numBottles;
            if(emptyBottles>=numExchange){
                numBottles+=1;
                emptyBottles-=numExchange;
                numExchange+=1;


            }
            else{
                break;
            }
            


        }
        return ans;
    }
};