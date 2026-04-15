class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int i = startIndex;
        int j = startIndex;
        int dis = 1e9;
        while (true) {
            if (words[i] == target) {
                if (i <= startIndex) {
                    dis = startIndex - i;
                } else {
                    dis = startIndex + n - i;
                }
                break;
            } else if (words[j] == target) {
                if (j >= startIndex) {
                    dis = j - startIndex;
                } else {
                    dis = n - startIndex + j;
                }
                break;
            }
            i = (i - 1 + n) % n;
            if (i == startIndex) {
                break;
            }
            j = (j + 1) % n;
            if (j == startIndex) {
                break;
            }
        }
        return dis == 1e9 ? -1 : dis;
    }
};