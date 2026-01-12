class Solution {
public:
    vector<vector<int>>ans;
    void solve(int st, int &n, int k, vector<int>& v){
        if(k==0){
            ans.push_back(v);
            return;
        }
        if(st>n){
            return;
        }
        v.push_back(st);
        solve(st+1, n, k-1, v);
        v.pop_back();
        solve(st+1, n, k, v);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>v;
        solve(1,n,k,v);
        return ans;
    }
};