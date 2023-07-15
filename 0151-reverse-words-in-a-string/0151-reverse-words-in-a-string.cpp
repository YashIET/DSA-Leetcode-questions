class Solution {
public:
    typedef int ll;
    string reverseWords(string s) {
        vector<string>v;
        string temp="";
        ll n=s.size();
        for(ll i=0;i<s.size();i++){
            if(s[i]==' ' && temp!=""){
                v.push_back(temp);
                // cout<<temp<<" ";
                temp="";
            }
            else if(s[i]!=' ')
            temp+=s[i];
            
        }
        if(temp!="")
        v.push_back(temp);
        // cout<<v.size();
        reverse(v.begin(),v.end());
        string temp2="";
        for(ll i=0;i<v.size();i++){
            temp2+=v[i];
            if(i!=v.size()-1)temp2+=" ";
        }
        return temp2;
    }
};