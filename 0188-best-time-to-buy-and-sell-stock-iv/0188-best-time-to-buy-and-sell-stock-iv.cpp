class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int>after(2*k+1,0),curr(2*k+1,0);
        for(int ind=n-1; ind>=0; ind--){
            for(int tsn=0; tsn<2*k; tsn++){
                if(tsn%2==0){
                   curr[tsn]=max(-prices[ind]+after[tsn+1],0+after[tsn]);
                }
                else{
                    curr[tsn]=max(prices[ind]+after[tsn+1],0+after[tsn]);
                }
            }
            after=curr;
        }
        return after[0];
        
    }
};