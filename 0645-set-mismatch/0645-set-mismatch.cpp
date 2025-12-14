class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
        long long s = 0, ss = 0;
        for (int& num : nums) {
            s += num;
            ss += num * num;
        }
        long long sf = (n * (n + 1)) / 2;
        long long ssf = (n * (n + 1) * (2 * n + 1)) / 6;
        long long ds = s - sf;
        long long dss = ss - ssf;
        int dupn = (ds * ds + dss) / (2 * ds);
        int missn = (dss - ds * ds) / (2 * ds);
        return {dupn, missn};
    }
};