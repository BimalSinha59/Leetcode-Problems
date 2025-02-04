class Solution {
public:
    string decToBinary(int num) {
        string ans = "";
        int n = num;
        while (n > 0) {
            int dig = n % 2;
            char ch = dig + '0';
            ans += ch;
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string convertDateToBinary(string date) {
        int n = date.size();
        int y = 1;
        int sum = 0;
        vector<string> v;
        // cout<<decToBinary(2080)<<" ";

        for (int i = n - 1; i >= 0; i--) {
            //cout << i << " ";
            if (date[i] == '-') {
                //cout << sum << " ";
                string temp = decToBinary(sum);
                v.push_back(temp);
                sum = 0;
                y = 1;
            } else {
                int x = date[i] - '0';
                sum += x * y;
                y *= 10;
            }
        }
        v.push_back(decToBinary(sum));
        string res = "";
        for (int j = v.size() - 1; j >= 0; j--) {
            res += v[j] + '-';
        }
        res.pop_back();
        return res;
    }
};