class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int i = startIndex;
        int dis1 = 1e9, dis2 = 1e9;
        while (true) {
            if (words[i] == target) {
                if (i <= startIndex) {
                    dis1 = startIndex - i;
                } else {
                    dis1 = startIndex + n - i;
                }
                break;
            }
            i = (i - 1 + n) % n;
            if (i == startIndex) {
                break;
            }
        }
        i = startIndex;
        while (true) {
            if (words[i] == target) {
                if (i >= startIndex) {
                    dis2 = i - startIndex;
                } else {
                    dis2 = n - startIndex + i;
                }
                break;
            }
            i = (i + 1) % n;
            if (i == startIndex) {
                break;
            }
        }
        int dis = min(dis1, dis2);
        return dis == 1e9 ? -1 : dis;
    }
};