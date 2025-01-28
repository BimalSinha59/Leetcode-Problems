class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n=answers.size();
        map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[answers[i]]++;
        }

        int ans=0;
        for(auto it:mp){
            if(it.second<=(it.first+1)){
                ans+=it.first+1;
            }
            else{
                int x=it.first+1;
                int mul=ceil(it.second/(double)x);
                ans+=(mul*x);
            }
        }
        return ans;
    }
};