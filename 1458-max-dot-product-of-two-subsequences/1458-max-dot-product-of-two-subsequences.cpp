class Solution {
public:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, int n,
              int m, vector<vector<int>>& dp) {

        if (i == n || j == m) {
            return -1e9;
        }
        if (dp[i][j] != INT_MIN) {
            return dp[i][j];
        }
        int pdt1 = nums1[i] * nums2[j];
        int pdt2 =
            nums1[i] * nums2[j] + solve(i + 1, j + 1, nums1, nums2, n, m, dp);
        int pdt3 = solve(i, j + 1, nums1, nums2, n, m, dp);
        int pdt4 = solve(i + 1, j, nums1, nums2, n, m, dp);
        return dp[i][j] = max({pdt1, pdt2, pdt3, pdt4});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1e9));
        //return solve(0, 0, nums1, nums2, n, m, dp);

        //bottom-up
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int pdt1 = nums1[i] * nums2[j];
                int pdt2 = nums1[i] * nums2[j] + dp[i+1][j+1];
                int pdt3 = dp[i][j+1];
                int pdt4 = dp[i+1][j];
                dp[i][j] = max({pdt1, pdt2, pdt3, pdt4});
            }
        }
        return dp[0][0];
    }
};