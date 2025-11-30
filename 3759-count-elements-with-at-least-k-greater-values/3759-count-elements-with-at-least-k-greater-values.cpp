class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int i=0,j=1;
        for(int i=0; i<n; i++){
            while(j<n && nums[j]==nums[i]){
                j++;
            }
            if(n-j>=k){
                ans++;
            }
        }
        return ans;
    }
};