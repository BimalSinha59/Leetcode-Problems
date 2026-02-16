class Solution {
public:
    int reverseBits(int n) {
        string r = "";
        while (n > 0) {
            r += (n % 2 == 0 ? "0" : "1");
            n /= 2;
        }
        while (r.size() < 32) {
            r.push_back('0');
        }
        int ans = stoi(r, nullptr, 2);
        return ans;
    }
};