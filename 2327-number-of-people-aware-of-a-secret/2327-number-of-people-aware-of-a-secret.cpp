class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {

        const int MOD = 1e9 + 7;
        vector<long long> knows(n, 0);
        knows[0] = 1;
        long long shared = 0, total = 1;

        for (int i = delay; i < forget && i < n; i++) {
            shared = (shared + knows[i - delay]) % MOD;
            total = (total + shared) % MOD;
            knows[i] = shared;
        }

        for (int i = forget; i < n; i++) {
            shared =
                (shared + knows[i - delay] - knows[i - forget] + MOD) % MOD;
            total = (total + shared - knows[i - forget] + MOD) % MOD;
            knows[i] = shared;
        }

        return total % MOD;
    }
};
