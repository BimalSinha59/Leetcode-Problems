class StockSpanner {
public:
    int ind;
    stack<pair<int,int>>st;
    StockSpanner() {
        ind=-1;
    }
    
    int next(int price) {
        ind++;
        int ans=1;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int pge=st.empty() ? -1:st.top().second;
        ans=ind-pge;
        st.push({price,ind});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */