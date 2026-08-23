class Solution {
public:
    vector<int> calculatePrimes(int num) {
        vector<bool> isPrime(num + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        vector<int> primes;
        for (int i = 2; i <= num; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = 2 * i; j <= num; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return primes;
    }
    vector<int> calculatePrimeFactors(int num, vector<int>& primes) {
        vector<int> factors;
        for (int& prime : primes) {
            if (1LL * prime * prime > num) {
                break;
            }
            if (num % prime == 0) {
                factors.push_back(prime);
                while (num % prime == 0) {
                    num /= prime;
                }
            }
        }
        if (num > 1) {
            factors.push_back(num);
        }
        return factors;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> primes = calculatePrimes(maxi);
        vector<vector<int>> prime_factors(maxi + 1);
        for (int i = 0; i <= maxi; i++) {
            prime_factors[i] = calculatePrimeFactors(i, primes);
        }
        vector<int> freq(maxi + 1, 0);
        int distinct = 0;
        int left = 0;
        int max_length = 0;
        for (int right = 0; right < n; right++) {
            for (int& factor : prime_factors[nums[right]]) {
                if (freq[factor] == 0) {
                    distinct++;
                }
                freq[factor]++;
            }
            while (distinct > k) {
                for (int& factor : prime_factors[nums[left]]) {
                    freq[factor]--;
                    if (freq[factor] == 0) {
                        distinct--;
                    }
                }
                left++;
            }
            int len = right - left + 1;
            max_length = max(max_length, len);
        }
        return max_length;
    }
};