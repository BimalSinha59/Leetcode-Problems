class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size(), m = version2.size();
        int i = 0, j = 0;
        int maxi = max(n, m);
        while (maxi > 0) {
            string str1, str2;
            while (i < n && version1[i] != '.') {
                str1.push_back(version1[i]);
                i++;
            }
            i++;
            while (j < m && version2[j] != '.') {
                str2.push_back(version2[j]);
                j++;
            }
            j++;
            int n1 = 0;
            if (!str1.empty()) {
                n1 = stoi(str1);
            }
            int n2 = 0;
            if (!str2.empty()) {
                n2 = stoi(str2);
            }
            if (n1 < n2) {
                return -1;
            } else if (n1 > n2) {
                return 1;
            }
            maxi -= max(str1.size() + 1, str2.size() + 1);
        }
        return 0;
    }
};