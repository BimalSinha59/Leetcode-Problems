class Solution {
public:
    int f(vector<int>& nums, int goal) {
        if (goal < 0) {
            return 0;
        }
        int n = nums.size();
        int l = 0, ans = 0, sum = 0;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // sol-> 1, TC=O(N), SC=O(N)
        // int n=nums.size();
        // unordered_map<int,int>mp;
        // int psum=0,ans=0;
        // mp[0]=1;
        // for(int i=0; i<n; i++){
        //     psum+=nums[i];
        //     int diff=psum-goal;
        //     ans+=mp[diff];
        //     mp[psum]++;
        // }
        // return ans;

        // sol->2 TC=O(4N),SC=O(1)

        return f(nums, goal) - f(nums, goal - 1);
    }
};