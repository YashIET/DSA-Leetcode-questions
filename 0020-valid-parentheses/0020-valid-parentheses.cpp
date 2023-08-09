#include<bits/stdc++.h>
class Solution {
     map<char,char>m;
    
public:
   
    bool isValid(string s) {
        m[')']='(';
        m['}']='{';
        m[']']='[';
        stack<char>st;
        for(int it=0;it<s.size();it++){
            char i=s[it];
            if(i=='(' || i=='{' || i=='['){
                st.push(i);
            }
            else{
                if(st.empty())return false;
                if(m[i]==st.top())st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};