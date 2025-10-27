class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int count = 0;
        vector<int> ans;
        for(int i= 0;i<n; i++){
            for(int j= 0; j<bank[i].length(); j++){
                if(bank[i][j]=='1'){
                    count++;
                }
            }
            if(count>0){
                ans.push_back(count);
            }
            count =0;
        }
        if(ans.size()==1) return 0;

        int i=0;
        int j=1;
        int answer =0;
        while(i>=0 && j<ans.size())
        {
            answer = answer+(ans[i]*ans[j]);
            i++;
            j++;
        }
        return answer;
    }
};