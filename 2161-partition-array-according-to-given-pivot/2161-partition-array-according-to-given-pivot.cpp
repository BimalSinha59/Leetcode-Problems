class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lessers, greaters;
        int pivot_cnt = 0;
        for (int& num : nums) {
            if (num < pivot) {
                lessers.push_back(num);
            } else if (num > pivot) {
                greaters.push_back(num);
            } else {
                pivot_cnt++;
            }
        }
        vector<int> ans;
        for (int& num : lessers) {
            ans.push_back(num);
        }
        while (pivot_cnt--) {
            ans.push_back(pivot);
        }
        for (int& num : greaters) {
            ans.push_back(num);
        }
        return ans;
    }
};