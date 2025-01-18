class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {

        int n=nums.size();
        int ans=abs(nums[0]-nums[n-1]);
        for(int i=1; i<n; i++){
            int x=abs(nums[i]-nums[i-1]);
            ans=max(x,ans);
        }
        return ans;
    }
};