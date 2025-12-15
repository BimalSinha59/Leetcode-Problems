class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int x=0;
            for(int j=0; j<n; j++){
                if(nums[j]<nums[i]){
                    x++;
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};