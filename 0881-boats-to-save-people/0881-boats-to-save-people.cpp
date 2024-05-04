class Solution {
public:
    typedef int ll;
    int numRescueBoats(vector<int>& people, int limit) {
        ll ans=0;
        sort(people.begin(),people.end());
        for(ll i=0,j=people.size()-1;i<=j;){
            if(i==j){ans++;i++;}
            else{
                if(people[i]+people[j]>limit){
                    ans++;
                    j--;
                }
                else{
                    ans++;
                    i++,j--;
                }
            }
        }
        return ans;
    }
};