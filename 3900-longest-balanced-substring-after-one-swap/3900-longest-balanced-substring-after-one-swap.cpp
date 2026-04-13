class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        vector<int> zs(n), os(n), diff(n);
        int zcnt = 0, ocnt = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                zcnt++;
            else
                ocnt++;
            zs[i] = zcnt;
            os[i] = ocnt;
            diff[i] = os[i] - zs[i];
        }
        int maxLen = 0;
        unordered_map<int, int> idx, zind, oind;
        idx[0] = -1;

        for (int i = 0; i < n; i++) {
            int pref = diff[i];

            if (idx.count(pref)) {
                maxLen = max(maxLen, i - idx[pref]);
            }
            if (idx.count(pref + 2)) {
                int j = idx[pref + 2];
                int subos = os[i] - (j >= 0 ? os[j] : 0);

                if (ocnt > subos)
                    maxLen = max(maxLen, i - j);
                else if (oind.count(pref + 2))
                    maxLen = max(maxLen, i - oind[pref + 2]);
            }
            if (idx.count(pref - 2)) {
                int j = idx[pref - 2];
                int subzs = zs[i] - (j >= 0 ? zs[j] : 0);

                if (zcnt > subzs)
                    maxLen = max(maxLen, i - j);
                else if (zind.count(pref - 2))
                    maxLen = max(maxLen, i - zind[pref - 2]);
            }

            if (!idx.count(pref))
                idx[pref] = i;
            if (!zind.count(pref) && zs[i] > 0)
                zind[pref] = i;
            if (!oind.count(pref) && os[i] > 0)
                oind[pref] = i;
        }
        return maxLen;
    }
};