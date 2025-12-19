class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = nums1.size(), m = nums2.size();
        pq.push({nums1[0] + nums2[0], 0, 0});
        while (!pq.empty() && k>0) {
            vector<int> v = pq.top();
            pq.pop();
            int idx1 = v[1], idx2 = v[2];
            ans.push_back({nums1[idx1],nums2[idx2]});
            k--;
            if (idx1 + 1 < n && st.find({idx1+1,idx2})==st.end()) {
                pq.push({nums1[idx1 + 1] + nums2[idx2], idx1 + 1, idx2});
                st.insert({idx1+1, idx2});
            }
            if (idx2 + 1 < m && st.find({idx1,idx2+1})==st.end()) {
                pq.push({nums1[idx1] + nums2[idx2 + 1], idx1, idx2 + 1});
                st.insert({idx1, idx2+1});
            }
        }
        return ans;
    }
};