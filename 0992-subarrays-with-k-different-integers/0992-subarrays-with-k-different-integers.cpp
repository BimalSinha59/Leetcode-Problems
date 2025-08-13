class Solution {
public:
    int f(vector<int>& nums,int n,int k){
        if(k<0){
            return 0;
        }
        int l=0,ans=0;
        unordered_map<int,int>mp;
        for(int r=0; r<n; r++){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return f(nums,n,k)-f(nums,n,k-1);
    }
};