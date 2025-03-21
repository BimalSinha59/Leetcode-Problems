class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int temp = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (i + nums[i] >= temp) {
                temp = i;
            }
        }
        cout<<temp;
        if (temp == 0) {
            return true;
        }
        return false;
    }
};