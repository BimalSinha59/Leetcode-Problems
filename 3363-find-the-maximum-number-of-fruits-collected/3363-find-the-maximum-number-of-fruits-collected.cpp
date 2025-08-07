class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += fruits[i][i];
        }

        for (int p = 0; p < 2; p++) {
            if (p == 1) {
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        swap(fruits[i][j], fruits[j][i]);
                    }
                }
            }

            vector<int> prev(n, -1), curr(n, -1);
            prev[n - 1] = fruits[0][n - 1];
            for (int i = 1; i < n - 1; i++) {
                for (auto it : curr) {
                    it = -1;
                }
                for (int j = 0; j < n; j++) {
                    if (prev[j] < 0) {
                        continue;
                    }
                    if (j - 1 >= 0) {
                        curr[j - 1] =
                            max(curr[j - 1], prev[j] + fruits[i][j - 1]);
                    }
                    if (j + 1 < n) {
                        curr[j + 1] =
                            max(curr[j + 1], prev[j] + fruits[i][j + 1]);
                    }
                    curr[j] = max(curr[j], prev[j] + fruits[i][j]);
                }
                prev = curr;
            }
            ans += prev[n - 1];
        }
        return ans;
    }
};