class Solution {
public:
    static bool cmp(pair<int,int>& a, pair<int,int>& b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    }
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> pfs(positive_feedback.begin(),positive_feedback.end());
        unordered_set<string> nfs(negative_feedback.begin(),negative_feedback.end());
        vector<pair<int,int>>ans;
        int n=report.size();
        for(int i=0; i<n; i++){
            string str=report[i];
            int pts=0;
            int m=str.size();
            int j=0;
            while(j<m){
                string temp;
                while(j<m && str[j]!=' '){
                    temp.push_back(str[j]);
                    j++;
                }
                if(pfs.count(temp)){
                    pts+=3;
                }
                else if(nfs.count(temp)){
                    pts--;
                }
                j++;
            }
            ans.push_back({pts,student_id[i]});
        }
        sort(ans.begin(),ans.end(),cmp);
        vector<int> fres;
        for(int i=0; i<k; i++){
            fres.push_back(ans[i].second);
        }
        return fres;
    }
};