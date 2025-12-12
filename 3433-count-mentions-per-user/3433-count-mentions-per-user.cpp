class Solution {
public:
    static bool cmp(vector<string>& a, vector<string>& b){
        int numA = stoi(a[1]);
        int numB = stoi(b[1]);

        if (numA != numB){
            return numA < numB;
        }

        if (a[0] == "OFFLINE" && b[0] == "MESSAGE") return true;
        if (a[0] == "MESSAGE" && b[0] == "OFFLINE") return false;

        return false;
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int>ans(numberOfUsers,0);
        vector<pair<int,int>>v(numberOfUsers);
        for(int i=0; i<numberOfUsers; i++){
            v[i].first=0;
            v[i].second=0;
        }
        sort(events.begin(),events.end(),cmp);
        for(auto &it:events){
            if(it[0]=="MESSAGE"){
                if(it[2]=="ALL"){
                    for(int &id:ans){
                        id++;
                    }
                }
                else if(it[2]=="HERE"){
                    for(int i=0; i<numberOfUsers; i++){
                        if(v[i].first==0){
                            ans[i]++;
                        }
                        else if(stoi(it[1])>=v[i].second+60){
                            ans[i]++;
                            v[i].first=0;
                        }
                    }
                }
                else{
                    string str;
                    for(int i=0; i<it[2].size(); i++){
                        if(it[2][i]>='0' && it[2][i]<='9'){
                            str.push_back(it[2][i]);
                        }
                        if(it[2][i]==' ' || i==it[2].size()-1){
                            int num=stoi(str);
                            ans[num]++;
                            str.clear();
                        }
                    }
                }
            }
            else{
                int num=stoi(it[2]);
                v[num].first=1;
                v[num].second=stoi(it[1]);
            }
        }
        return ans;
    }
};