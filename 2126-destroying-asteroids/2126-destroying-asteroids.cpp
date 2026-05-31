class Solution {
public:
    vector<int> countingSort(vector<int>& nums) {
        int n = nums.size();
        int maxVal = 0;
        for (int i = 0; i < n; i++) {
            maxVal = max(maxVal, nums[i]);
        }
        vector<int> count(maxVal + 1, 0);
        for (int i = 0; i < n; i++) {
            count[nums[i]]++;
        }
        for (int i = 1; i <= maxVal; i++) {
            count[i] += count[i - 1];
        }
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            ans[count[nums[i]] - 1] = nums[i];
            count[nums[i]]--;
        }
        return ans;
    }
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        asteroids = countingSort(asteroids);
        long long sum = mass;
        for (int i = 0; i < asteroids.size(); i++) {
            if (sum < asteroids[i]) {
                return false;
            }
            sum += asteroids[i];
        }
        return true;
    }
};