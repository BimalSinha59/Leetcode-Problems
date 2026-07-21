class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int oneCount = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                oneCount++;
            }
        }
        int prevZeroCount = 0, currZeroCount = 0;
        int i = 0;
        int maxi = 0;
        while (i < n) {
            while (i < n && s[i] == '0') {
                currZeroCount++;
                i++;
            }
            int sum = 0;
            if (prevZeroCount != 0) {
                sum = prevZeroCount + currZeroCount;
            }
            maxi = max(maxi, sum);
            prevZeroCount = currZeroCount;
            currZeroCount = 0;
            while (i < n && s[i] == '1') {
                i++;
            }
        }
        int totalOneCount = oneCount + maxi;
        return totalOneCount;
    }
};