class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        vector<int>ans(n);
        sort(potions.begin(),potions.end());
        for(int i=0; i<n; i++){
            int idx=-1;
            int s=0,e=m-1;
            while(s<=e){
                int mid=(s+e)/2;
                if(spells[i]*1LL*potions[mid]>=success){
                    idx=mid;
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            if(idx==-1){
                ans[i]=0;
            }
            else{
                ans[i]=(m-idx);
            }
        }
        return ans;
    }
};