class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> arr;
        int n=startTime.size();
        arr.push_back(startTime[0]);
        for(int i=1; i<n; i++){
            int x=startTime[i]-endTime[i-1];
            arr.push_back(x);
        }
        arr.push_back(eventTime-endTime[n-1]);

        int temp=k+1;
        long long sum=0;
        for(int i=0; i<temp; i++){
            sum+=arr[i];
        }
        // for(int i=0; i<arr.size(); i++){
        //     cout<<arr[i]<<" ";
        // }
        long long maxA=sum;
        for(int i=temp; i<arr.size(); i++){
            long long tsum=sum+arr[i]-arr[i-temp];
            sum=tsum;
            maxA=max(maxA,tsum);
        }
        return maxA;
    }
};