class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int,long long>,vector<pair<int,long long>>> buy_backlog;
        priority_queue<pair<int,long long>,vector<pair<int,long long>>,greater<pair<int,long long>>> sell_backlog;
        for(auto it:orders){
            int order_type=it[2];
            int amount=it[1];
            int price=it[0];
            if(order_type==0){
                while(!sell_backlog.empty() && sell_backlog.top().first<=price && amount>0){
                    int sell_amount=sell_backlog.top().second;
                    int sell_price=sell_backlog.top().first;
                    sell_backlog.pop();
                    if(amount>=sell_amount){
                        amount-=sell_amount;
                    }
                    else{
                        sell_amount=sell_amount-amount;
                        sell_backlog.push({sell_price,sell_amount});
                        amount=0;
                    }

                }
                if(amount>0){
                    buy_backlog.push({price,amount});
                }
            }
            else{
                while(!buy_backlog.empty() && buy_backlog.top().first>=price && amount>0){
                    int buy_amount=buy_backlog.top().second;
                    int buy_price=buy_backlog.top().first;
                    buy_backlog.pop();
                    if(amount>=buy_amount){
                        amount-=buy_amount;
                    }
                    else{
                        buy_amount=buy_amount-amount;
                        buy_backlog.push({buy_price,buy_amount});
                        amount=0;
                    }

                }
                if(amount>0){
                    sell_backlog.push({price,amount});
                }

            }

        }
        long long ans=0;
        int MOD=1e9+7;
        while(!buy_backlog.empty()){
            ans=(ans+buy_backlog.top().second)%MOD;
            buy_backlog.pop();
        }
        while(!sell_backlog.empty()){
            ans=(ans+sell_backlog.top().second)%MOD;
            sell_backlog.pop();
        }
        return ans;
        
    }
};