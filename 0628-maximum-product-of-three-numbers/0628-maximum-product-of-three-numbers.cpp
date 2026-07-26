class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int first_max=INT_MIN, second_max=first_max, third_max=second_max;
        int first_min=INT_MAX, second_min=first_min;
        for(int &num:nums){
            int prev_first_max=first_max,prev_second_max=second_max, prev_first_min=first_min;
            first_max=max(first_max, num);
            second_max=max(second_max, min(prev_first_max, num));
            third_max=max(third_max, min(prev_second_max, num));
            first_min=min(first_min, num);
            second_min=min(second_min, max(prev_first_min, num));
        }
        int maxProduct=max(first_max*second_max*third_max, first_max*first_min*second_min);
        return maxProduct;
    }
};