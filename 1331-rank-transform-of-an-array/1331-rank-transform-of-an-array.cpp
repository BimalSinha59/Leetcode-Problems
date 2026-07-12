class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> ele_idx;
        for (int i = 0; i < n; i++) {
            ele_idx.push_back({arr[i], i});
        }
        sort(ele_idx.begin(), ele_idx.end());
        vector<int> ranks(n);
        int i = 0;
        int rank = 0;
        while (i < n) {
            if (i - 1 >= 0 && ele_idx[i].first == ele_idx[i - 1].first) {
                ranks[ele_idx[i].second] = rank;
            } else {
                rank++;
                ranks[ele_idx[i].second] = rank;
            }
            i++;
        }
        return ranks;
    }
};