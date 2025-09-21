class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans=0;
        for(auto it:nums){
            if(it%2==0){
                ans=(ans|it);
            }
        }
        return ans;
    }
};