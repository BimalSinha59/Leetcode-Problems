class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n=s.size();
        set<string>st;
        int nsize=n/k;

        map<string,int>mp1,mp2;
        for(int i=0; i<n; i=i+nsize){
            string str=s.substr(i,nsize);
            mp1[str]++;
            //cout<<str<<" ";
            st.insert(str);
        }

        set<string> st2;
         for(int i=0; i<n; i=i+nsize){
            string str=t.substr(i,nsize);
             mp2[str]++;
            //cout<<str<<" ";
            st2.insert(str);
        }

        bool t1=true,t2=true;
        for(int i=0; i<n; i+=nsize){
            string str2=t.substr(i,nsize);
            if(st.find(str2)==st.end()){
               t1=false;
            }
            if(!t1) break;
        }
        for(int i=0; i<n; i+=nsize){
            string str2=s.substr(i,nsize);
            if(st2.find(str2)==st2.end()){
               t2=false;
            }
            if(!t2) break;
        }

        bool t3=true,t4=true;

         for(int i=0; i<n; i=i+nsize){
            string str=s.substr(i,nsize);
            if(mp1[str]!=mp2[str]){
                t3=false;
                break;
            }
        }

         for(int i=0; i<n; i=i+nsize){
            string str=t.substr(i,nsize);
             if(mp1[str]!=mp2[str]){
                t4=false;
                break;
            }
        }

        
       
        return t1&t2&t3&t4;
    }
};