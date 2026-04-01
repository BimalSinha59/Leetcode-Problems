class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> ids(n);
        for (int i = 0; i < n; i++) {
            ids[i] = i;
        }
        sort(ids.begin(), ids.end(), [&](int a, int b) { 
            return positions[a] < positions[b]; 
        });

        vector<int> st;
        for (int id : ids) {
            if (directions[id] == 'R') {
                st.push_back(id);
            } else {
                while (!st.empty() && directions[st.back()] == 'R' &&
                       healths[id] > 0) {
                    int topId = st.back();
                    if (healths[id] > healths[topId]) {
                        healths[topId] = 0;
                        healths[id] -= 1;
                        st.pop_back();
                    } else if (healths[id] < healths[topId]) {
                        healths[id] = 0;
                        healths[topId] -= 1;
                    } else {
                        healths[id] = 0;
                        healths[topId] = 0;
                        st.pop_back();
                    }
                }
                if (healths[id] > 0) {
                    st.push_back(id);
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};