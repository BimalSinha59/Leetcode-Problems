class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_set<int> st;
        vector<int> C(n, 0);
        for (int i = 0; i < n; i++) {
            st.insert(A[i]);
            st.insert(B[i]);
            int PrefixCommonElements = 2 * (i + 1) - st.size();
            C[i] = PrefixCommonElements;
        }
        return C;
    }
};