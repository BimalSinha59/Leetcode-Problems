class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(),skill.end());
        int i=0,j=n-1;
        int sum=0;
        long long ans=0;
        while(i<j){
            int nsum=skill[i]+skill[j];
            if(i==0){
                sum=nsum;
            }
            if(i!=0 && nsum!=sum){
                return -1;
            }
            long long mul=skill[i]*skill[j];
            ans+=mul;
            i++;
            j--;
        }
        return ans;
    }
};