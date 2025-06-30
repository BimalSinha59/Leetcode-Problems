class Solution {
public:
    vector<int> findPSEE(vector<int>& arr, int n){
        vector<int>ans(n);
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> findNSE(vector<int>& arr,int n){
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        auto psee = findPSEE(arr,n);
        auto nse = findNSE(arr,n);
        int ans=0;
        int mod=(int)(1e9+7);
        for(int i=0; i<n; i++){
            int left = i-psee[i];
            int right = nse[i]-i;
            ans = (ans+(1LL*left*right*arr[i])%mod)%mod;
        }
        return ans;
    }
};