class Solution {
public:
    bool isPrime(long long &n) {
        if (n <= 1) {
            return false;
        }
        else{
            long long cnt=0;
            for (long long i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    cnt++;
                }
            }
            if (cnt > 0) {
                return false;
            }
            return true;
        }
    }
    long long sumOfLargestPrimes(string s) {
        int n = s.size();
        vector<long long> v;
        for (int i = 0; i < n; i++) {
            string str = "";
            for (int j = i; j < n; j++) {
                str += s[j];
                long long num = 0;
                long long mul=1;
                for(int k=str.size()-1; k>=0; k--){
                    int x=str[k]-'0';
                    num+=(x*mul);
                    mul*=10;
                    
                }
                v.push_back(num);
            }
        }
        sort(v.rbegin(), v.rend());
        set<long long> st;
        long long sum = 0;
        int c = 0;
        for (int i = 0; i < v.size(); i++) {
            if (isPrime(v[i]) && st.find(v[i]) == st.end()) {
                sum += v[i];
                c++;
                st.insert(v[i]);
                if (c == 3) {
                    break;
                }
            }
        }
        return sum;
    }
};