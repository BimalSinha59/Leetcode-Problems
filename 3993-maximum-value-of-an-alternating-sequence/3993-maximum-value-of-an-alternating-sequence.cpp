class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1) {
            return s;
        }
        if (m == 1) {
            return s + 1;
        }
        long long first_term, no_of_terms, comm_diff = m - 1;
        if (n & 1) {
            first_term = s + 1;
            no_of_terms = ceil(n / 2.0);
        } else {
            first_term = s + m;
            no_of_terms = n / 2;
        }
        long long maxi = first_term + (no_of_terms - 1) * comm_diff;
        return maxi;
    }
};