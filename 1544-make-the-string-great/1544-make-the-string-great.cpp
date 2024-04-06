class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        int i=1,n=s.size();
        st.push(s[0]);
        while(i<n){
            if(st.empty()){
                st.push(s[i]);i++;
                continue;
            }
            char pre=st.top();
            char ch1=toupper(st.top());
            char ch2=tolower(st.top());
            if((ch1==s[i] &&ch1!=pre)||(ch2==s[i]&&ch2!=pre)  ){
                st.pop();
                
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        string ans="";
        while(!st.empty()){
            char temp=st.top();
            cout<<temp;
            st.pop();
            ans+=(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};