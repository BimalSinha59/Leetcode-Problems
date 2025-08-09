class Solution {
public:
    int f(vector<int>& nums,int n, int k){
        int ans=0;
        int psum=0;
        int l=0;
        for(int r=0; r<n; r++){
            psum+=nums[r]%2;
            while(psum>k){
                psum-=nums[l]%2;
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        // unordered_map<int, int> mp;
        // int ans = 0;
        // int psum = 0;
        // mp[0] = 1;
        // for (int i = 0; i < n; i++) {
        //     psum += nums[i] % 2;
        //     int diff = psum - k;
        //     ans += mp[diff];
        //     mp[psum]++;
        // }
        // return ans;

        return f(nums,n,k)-f(nums,n,k-1);
    }
};