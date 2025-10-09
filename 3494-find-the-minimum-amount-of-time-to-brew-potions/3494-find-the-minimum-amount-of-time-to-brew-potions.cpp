class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long> tm(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    tm[0] = tm[0] + skill[0] * 1LL * mana[i];
                } 
                else {
                    tm[j] = max(tm[j], tm[j - 1]) + skill[j] * 1LL * mana[i];
                }
            }
            for (int j = n - 2; j >= 0; j--) {
                tm[j] = tm[j + 1] - skill[j + 1] * 1LL * mana[i];
            }
        }
        return tm[n - 1];
    }
};