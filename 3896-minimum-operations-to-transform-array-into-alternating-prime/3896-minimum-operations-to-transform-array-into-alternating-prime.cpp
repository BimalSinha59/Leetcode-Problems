class Solution {
public:
    vector<bool> prime;
    vector<int> soe(int n) {
        prime.resize(n + 1, true);
        prime[0] = false, prime[1] = false;
        for (int p = 2; p * p <= n; p++) {

            if (prime[p] == true) {

                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        vector<int> primes;
        for (int p = 2; p <= n; p++) {
            if (prime[p]) {
                primes.push_back(p);
            }
        }
        return primes;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> primes = soe(2e5);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                if (prime[nums[i]]) {
                    ans += (nums[i] == 2 ? 2 : 1);
                }
            } else {
                if (!prime[nums[i]]) {
                    int s = 0, e = primes.size() - 1;
                    int idx = -1;
                    while (s <= e) {
                        int mid = (s + e) / 2;
                        if (primes[mid] >= nums[i]) {
                            idx = mid;
                            e = mid - 1;
                        } else {
                            s = mid + 1;
                        }
                    }
                    int diff = primes[idx] - nums[i];
                    ans += diff;
                }
            }
        }
        return ans;
    }
};