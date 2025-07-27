class Solution {
public:
    long long numOfSubsequences(string s) {
        int n=s.size();
        vector<int> plc(n,0),stc(n,0);
        for(int i=0; i<n; i++){
            if(i-1>=0){
                plc[i]=plc[i-1];
            }
            if(s[i]=='L'){
                plc[i]++;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(i+1<n){
                stc[i]=stc[i+1];
            }
            if(s[i]=='T'){
                stc[i]++;
            }
        }
        long long ans=0;
        long long lians=0,tians=0,cians=0;
        long long maxi=0;
        for(int i=0; i<n; i++){
            long long lc=plc[i];
            long long tc=stc[i];
            if(s[i]=='C'){
                ans+=lc*tc;
                lians+=(lc+1)*tc;
                tians+=lc*(tc+1);
            }
            maxi=max(maxi,lc*tc);
        }
        cians=ans+maxi;
        return max({lians,tians,cians});
    }
};