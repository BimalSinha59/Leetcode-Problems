class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n=c.size();
        int ps[n+1],ss[n+1];
        ps[0]=0;
        for(int i=1; i<=n; i++){
            ps[i]=ps[i-1]+c[i-1];
        }
        ss[0]=0;
        for(int i=n-1; i>=0; i--){
            ss[n-i]=ss[n-i-1]+c[i];
        }
        int ans=0;
        for(int i=0; i<=k; i++){
            ans=max(ans,ps[i]+ss[k-i]);
        }
        return ans;
    }
};