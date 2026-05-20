class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int& num : nums) {
            mp[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto [num, freq] : mp) {
            pq.push({freq, num});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};