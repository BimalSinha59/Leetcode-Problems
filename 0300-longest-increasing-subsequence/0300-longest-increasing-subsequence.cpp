class Solution {
public:
    int f(int ind, int p_end, vector<int>& nums, int n,
          vector<vector<int>>& dp) {
        if (ind == n) {
            return 0;
        }
        if (dp[ind][p_end + 1] != -1) {
            return dp[ind][p_end + 1];
        }
        int len = 1;
        len = 0 + f(ind + 1, p_end, nums, n, dp);
        if (p_end == -1 || nums[ind] > nums[p_end]) {
            len = max(len, 1 + f(ind + 1, ind, nums, n, dp));
        }
        return dp[ind][p_end + 1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return f(0,-1,nums,n,dp);

        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        //////////***SO***//////////
        // vector<int>next(n+1,0),curr(n+1,0);
        // for(int ind=n-1;ind>=0; ind--){
        //     for(int p_end=ind-1;p_end>=-1; p_end--){
        //         int len=0+next[p_end+1];
        //         if(p_end==-1 || nums[ind]>nums[p_end]){
        //             len=max(len,1+next[ind+1]);
        //         }
        //         curr[p_end+1]=len;
        //     }
        //     next=curr;
        // }
        // return next[0];

        ///////TABULATION dp[n] method/////////
        // vector<int>dp(n,1);
        // int maxi=1;
        // for(int i=1; i<n; i++){
        //     for(int j=0; j<i; j++){
        //         if(nums[i]>nums[j]){
        //             dp[i]=max(dp[i],1+dp[j]);
        //         }
        //     }
        //     maxi=max(maxi,dp[i]);
        // }
        // return maxi;

        //////*****LIS using BINARY SEARCH*****/////////
        vector<int> temp;
        temp.push_back(nums[0]);
        int lisLen = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                lisLen++;
            } else {
                int low = 0, high = temp.size() - 1;
                int idx;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (temp[mid] < nums[i]) {
                        low = mid + 1;
                    } else {
                        idx = mid;
                        high = mid - 1;
                    }
                }
                temp[idx] = nums[i];
            }
        }
        return lisLen;
    }
};