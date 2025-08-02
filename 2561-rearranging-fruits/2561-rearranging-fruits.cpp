class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();

        long long cost = 0;
        unordered_map<int, int> mp1, mp2;
        int mini = 1e9 + 7;
        for (auto it : basket1) {
            mini = min(mini, it);
            mp1[it]++;
        }
        for (auto it : basket2) {
            mini = min(mini, it);
            mp2[it]++;
        }
        map<int, int> mp;
        for (auto it : mp1) {
            int f1 = it.second;
            int f2 = mp2[it.first];
            if ((f1 + f2) & 1) {
                return -1;
            } else {
                int sr = ((abs(f1 - f2)) / 2);
                mp[it.first] = sr;
            }
        }
        for (auto it : mp2) {
            if (mp1.find(it.first) == mp1.end()) {
                int f = it.second;
                if (f & 1) {
                    return -1;
                } else {
                    int sr = (f / 2);
                    mp[it.first] = sr;
                }
            }
        }

        vector<int> v;
        for (auto it : mp) {
            for (int i = 0; i < it.second; i++) {
                v.push_back(it.first);
            }
        }
        for (int i = 0; i < v.size(); i++) {
            if (i == v.size() / 2) {
                break;
            }
            cost += min(v[i], 2 * mini);
        }
        return cost;
    }
};