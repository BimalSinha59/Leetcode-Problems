class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        queue<int>q;
        for(int i=0; i<n; i++){
            q.push(students[i]);
        }
        int idx=0;
        while(!q.empty()){
            int fst=q.front();
            if(fst==sandwiches[idx]){
                q.pop();
                idx++;
            }
            else{
                int cnt=0;
                while(!q.empty() && q.front()!=sandwiches[idx]){
                    cnt++;
                    if(cnt==q.size()){
                        return cnt;
                    }
                    int nfst=q.front();
                    q.pop();
                    q.push(nfst);
                }
            }
        }
        return 0;
    }
};