class Solution {
public:
    int tribonacci(int n) {
        vector<int>v;
        v.push_back(0);
        v.push_back(1);
        v.push_back(1);
        if(n>2){
            for(int i=2;i<n;i++){
                int temp=v.size();
                v.push_back(v[temp-1]+v[temp-2]+v[temp-3]);
            }
            return v[n];
        }
        else return v[n];
    }
};