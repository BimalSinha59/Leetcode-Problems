class Solution {
public:
    class SmtWindow{
    public:
        int K;
        multiset<int> low, high;
        long long sLow = 0;

        SmtWindow(int k) : K(k) {}

        int windowSize() const{
            return (int)low.size() + (int)high.size();
        }
        void rebalance() {
            int req = min(K, windowSize());

            while((int)low.size() > req){
                auto it = prev(low.end());
                int x = *it;
                low.erase(it);
                sLow -= x;
                high.insert(x);
            }
            while((int)low.size() < req && !high.empty()){
                auto it = high.begin();
                int x = *it;
                high.erase(it);
                low.insert(x);
                sLow += x;
            }
        }
        void add(int x){
            if(low.empty() || x <= *prev(low.end())){
                low.insert(x);
                sLow += x;
            }
            else{
                high.insert(x);
            }
            rebalance();
        }
        void remove(int x){
            auto itLow = low.find(x);
            if(itLow != low.end()){
                low.erase(itLow);
                sLow -= x;
            }
            else{
                auto itHigh = high.find(x);
                if(itHigh != high.end()){
                    high.erase(itHigh);
                }
            }
            rebalance();
        }
        long long query() const{
            return sLow;
        }
    };
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = (int)nums.size();
        k -= 1;
        SmtWindow window(k);
        for(int i = 1; i <= 1 + dist; i ++){
            window.add(nums[i]);
        }
        long long ans = window.query();
        for(int i = 2; i + dist < n; i ++){
            window.remove(nums[i - 1]);
            window.add(nums[i + dist]);
            ans = min(ans, window.query());
        }
        return ans + nums[0];
    }
};