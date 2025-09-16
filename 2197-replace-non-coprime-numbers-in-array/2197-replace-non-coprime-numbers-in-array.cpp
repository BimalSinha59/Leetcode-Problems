class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for (int it : nums) {
            ans.push_back(it);
            while (ans.size() > 1) {
                int a = ans.back();
                int b = ans[ans.size() - 2];
                int g = gcd(a, b);
                if (g > 1) {
                    ans.pop_back();
                    ans.pop_back();
                    long long lcm = (long long)a / g * b;
                    ans.push_back((int)lcm);
                } 
                else {
                    break;
                }
            }
        }
        return ans;
    }
};