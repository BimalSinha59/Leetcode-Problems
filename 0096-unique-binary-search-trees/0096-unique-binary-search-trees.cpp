class Solution {
public:
    int numTrees(int n) {
        vector<int> v;
        v.push_back(0);
        v.push_back(1);
        v.push_back(2);
        v.push_back(5);
        for (int i = 4; i <= n; i++) {
            int ans = 0;
            if(i>n){
                break;
            }
            for(int j=1; j<=i; j++){
                int l=j-1;
                if(l==1) l=0;
                int r=i-j;
                if(r==1) r=0;
                if(l>1 && r>1){
                    ans+=v[l]*v[r];
                }
                else{
                    ans+=v[l]+v[r];
                }
            }
            v.push_back(ans);
        }
        return v[n];
    }
};