class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adjL[n];
        for (auto& flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            adjL[from].push_back({to, price});
        }
        queue<vector<int>> q;
        vector<int> tprice(n, 1e9);
        q.push({0, src, 0});
        tprice[src] = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int stops = node[0];
            int fcity = node[1];
            int fprice = node[2];
            if (stops > k) {
                continue;
            }
            for (auto& adjCity : adjL[fcity]) {
                int dcity = adjCity.first;
                int dprice = adjCity.second;
                if (fprice + dprice < tprice[dcity] && stops <= k) {
                    tprice[dcity] = fprice + dprice;
                    q.push({stops + 1, dcity, tprice[dcity]});
                }
            }
        }
        return tprice[dst] == 1e9 ? -1 : tprice[dst];
    }
};