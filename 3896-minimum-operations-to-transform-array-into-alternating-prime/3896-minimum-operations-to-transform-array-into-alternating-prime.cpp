class Solution {
public:
    vector<bool> is_prime;
    vector<int> soe(int n) {
        is_prime.resize(n + 1, true);
        is_prime[0] = false, is_prime[1] = false;
        for (int p = 2; p * p <= n; p++) {

            if (is_prime[p] == true) {

                for (int i = p * p; i <= n; i += p)
                    is_prime[i] = false;
            }
        }

        vector<int> primes;
        for (int p = 2; p <= n; p++) {
            if (is_prime[p]) {
                primes.push_back(p);
            }
        }
        return primes;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> primes = soe(1e5 + 5);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                if (is_prime[nums[i]]) {
                    ans += (nums[i] == 2 ? 2 : 1);
                }
            } else {
                if (!is_prime[nums[i]]) {
                    int idx =
                        lower_bound(primes.begin(), primes.end(), nums[i]) - primes.begin();
                    int diff = primes[idx] - nums[i];
                    ans += diff;
                }
            }
        }
        return ans;
    }
};