class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        int i=0;
        while(i<n){
            int j=i;
            long long c=0;
            while(j<n && nums[j]==0){
                c++;
                j++;
            }
            ans+=((c*(c+1))/2);
            i=j;
            i++;
        }
        return ans;
    }
};