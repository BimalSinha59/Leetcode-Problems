class Solution {
public:
    void nextSmaller(vector<int>& arr,int n, vector<int>&next){
        stack<int>st;
        st.push(-1);
        for(int i=n-1; i>=0; i--){
            int ele = arr[i];
            while(!st.empty() && st.top()!=-1 && arr[st.top()]>ele){
                st.pop();
            }
            next.push_back(st.top());
            st.push(i);
        }
    }
    void prevSmaller(vector<int>&arr,int n, vector<int>&prev){
        stack<int>st;
        st.push(-1);
        for(int i=0; i<n; i++){
            int ele=arr[i];
            while(!st.empty() && st.top()!=-1 && arr[st.top()]>=ele){
                st.pop();
            }
            prev.push_back(st.top());
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>next;
        vector<int>prev;
        int n=arr.size();
        nextSmaller(arr,n,next);
        reverse(next.begin(),next.end());

        for(int i=0; i<n; i++){
            if(next[i]==-1){
                next[i]=n;
            }
        }

        prevSmaller(arr,n,prev);
        const int mod = 1e9+7;
        long long sum=0;
        for(int i=0; i<n; i++){
            int nextS=next[i]-i;
            int prevS=i-prev[i];
            long long mul=((nextS%mod)*(prevS%mod))%mod;
            long long total=(mul*arr[i])%mod;
            sum=(sum+total)%mod;
        }
        return sum;
    }
};