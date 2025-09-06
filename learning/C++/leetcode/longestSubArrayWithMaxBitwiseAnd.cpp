#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> v){
    int ans=0;
    int mx=0;
    for(int i=0;i<v.size(); ++i)
        mx = max(mx, v[i]);
    

    for(int i=0; i<v.size(); ++i){
        int cnt = 0;
        while(i<v.size() && v[i]==mx){
            ++cnt;
            ++i;
        }

        ans = max(ans, cnt);
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];
    
    cout << solve(v) << endl;
    return 0;
}