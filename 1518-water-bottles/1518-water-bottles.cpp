class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0;
        int extra_bottles=0;
        
        while(numBottles>0){
            ans+=numBottles;
            numBottles=((numBottles+extra_bottles)/numExchange);
            cout << numBottles << " ";
            extra_bottles=(numBottles+extra_bottles)%numExchange;
            cout << extra_bottles <<" ";
            cout <<endl;

        }
        return ans;
        
    }
};