class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<long long> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = nums[i];
        }

        set<pair<long long, int>> st;

        vector<int> nidx(n);
        vector<int> pidx(n);

        for (int i = 0; i < n; i++) {
            nidx[i] = i + 1;
            pidx[i] = i - 1;
        }

        int badPairs = 0;
        for (int i = 0; i < n - 1; i++) {
            if (temp[i] > temp[i + 1]) {
                badPairs++;
            }
            st.insert({temp[i] + temp[i + 1], i});
        }

        int ans = 0;

        while (badPairs > 0) {
            int first = st.begin()->second;
            int second = nidx[first];

            int first_left = pidx[first];
            int second_right = nidx[second];

            st.erase(begin(st));

            if (temp[first] > temp[second]) {
                badPairs--;
            }

            if (first_left >= 0) {
                if (temp[first_left] > temp[first] &&
                    temp[first_left] <= temp[first] + temp[second]) {
                    badPairs--;
                } else if (temp[first_left] <= temp[first] &&
                           temp[first_left] > temp[first] + temp[second]) {
                    badPairs++;
                }
            }

            if (second_right < n) {
                if (temp[second_right] >= temp[second] &&
                    temp[second_right] < temp[first] + temp[second]) {
                    badPairs++;
                } else if (temp[second_right] < temp[second] &&
                           temp[second_right] >= temp[first] + temp[second]) {
                    badPairs--;
                }
            }

            if (first_left >= 0) {
                st.erase({temp[first_left] + temp[first], first_left});
                st.insert({temp[first_left] + temp[first] + temp[second],
                           first_left});
            }

            if (second_right < n) {
                st.erase({temp[second] + temp[second_right], second});
                st.insert(
                    {temp[first] + temp[second] + temp[second_right], first});
                pidx[second_right] = first;
            }

            nidx[first] = second_right;
            temp[first] += temp[second];

            ans++;
        }

        return ans;
    }
};
