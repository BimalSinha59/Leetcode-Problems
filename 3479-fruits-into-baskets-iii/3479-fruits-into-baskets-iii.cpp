class Solution {
public:
    int sgt[400007];
    void build(int ind, int low, int high, vector<int>& baskets) {
        if (low == high) {
            sgt[ind] = baskets[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, baskets);
        build(2 * ind + 2, mid + 1, high, baskets);
        sgt[ind] = max(sgt[2 * ind + 1], sgt[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {
        if (high < l || r < low) {
            return INT_MIN;
        }
        if (low >= l && high <= r) {
            return sgt[ind];
        }

        int mid = (high + low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return max(left, right);
    }

    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            sgt[ind] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid) {
            update(2 * ind + 1, low, mid, i, val);
        } 
        else {
            update(2 * ind + 2, mid + 1, high, i, val);
        }
        sgt[ind] = max(sgt[2 * ind + 1], sgt[2 * ind + 2]);
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int ans = 0;
        build(0, 0, n - 1, baskets);

        for (int i = 0; i < n; i++) {
            int s = 0, e = n - 1, idx = -1;
            while (s <= e) {
                int mid = (s + e) / 2;
                if (query(0, 0, n - 1, 0, mid) >= fruits[i]) {
                    idx = mid;
                    e = mid - 1;
                }
                else {
                    s = mid + 1;
                }
            }
            if (idx != -1 && baskets[idx] >= fruits[i]) {
                update(0, 0, n - 1, idx, INT_MIN);
            } 
            else {
                ans++;
            }
        }
        return ans;
    }
};