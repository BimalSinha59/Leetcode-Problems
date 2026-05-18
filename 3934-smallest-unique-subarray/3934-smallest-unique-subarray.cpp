class Solution {
public:
    struct pair_hash {
        template <class T1, class T2>
        size_t operator () (const pair<T1, T2>& p) const {
            auto h1 = hash<T1>{}(p.first);
            auto h2 = hash<T2>{}(p.second);
            return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
        }
    };

    bool RollingHash(const vector<int>& nums, int k) {
        int n = nums.size();

        const long long MOD1 = 1e9 + 7;
        const long long MOD2 = 1e9 + 9;
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        const long long B1 = uniform_int_distribution<long long>(300, MOD1 - 2)(rng) | 1; 
        const long long B2 = uniform_int_distribution<long long>(300, MOD2 - 2)(rng) | 1; 

        pair<long long, long long> h = {0, 0};
        pair<long long, long long> p = {1, 1};

        for (int i = 0; i < k; ++i) {
            long long val = (nums[i] % MOD1 + MOD1) % MOD1; 
            h.first  = (h.first * B1 + val) % MOD1;
            h.second = (h.second * B2 + val) % MOD2;
            p.first  = (p.first * B1) % MOD1;
            p.second = (p.second * B2) % MOD2;
        }
        unordered_map<pair<long long, long long>, int, pair_hash> mp;
        mp[h]++;
        for (int i = k; i < n; ++i) {
            long long next_val = (nums[i] % MOD1 + MOD1) % MOD1;
            long long prev_val = (nums[i - k] % MOD1 + MOD1) % MOD1;
            h.first = (h.first * B1 + next_val - (prev_val * p.first % MOD1) + MOD1) % MOD1;
            h.second = (h.second * B2 + next_val - (prev_val * p.second % MOD2) + MOD2) % MOD2;
            mp[h]++;
        }
        for(auto it:mp){
            if(it.second==1){
                return true;
            }
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int s=1,e=n;
        int ans=1;
        while(s<=e){
            int mid=(s+e)/2;
            if(RollingHash(nums,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};