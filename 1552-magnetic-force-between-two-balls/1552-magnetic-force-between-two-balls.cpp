class Solution {
public:
    bool isPossibleToPut(vector<int>& position, int minForce, int n, int m) {
        int lastPos = position[0];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (position[i] - lastPos >= minForce) {
                cnt++;
                lastPos = position[i];
                if (cnt == m) {
                    return true;
                }
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int s = 1, e = position[n - 1] - position[0];
        int ans = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isPossibleToPut(position, mid, n, m)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
};