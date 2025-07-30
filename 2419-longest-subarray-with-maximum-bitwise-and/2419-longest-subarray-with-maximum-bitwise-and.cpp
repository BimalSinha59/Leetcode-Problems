class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        int i=0;
        int maxLen=0;
        while(i<n){
            int c=0;
            while(i<n && nums[i]==maxi){
                c++;
                i++;
            }
            maxLen=max(maxLen,c);
            i++;
        }
        return maxLen;
    }
};