#include <bits/stdc++.h>
using namespace std;



int solve(vector<int> v){
    int ans = 1;
    int i=0,j=0;
    while(j<v.size() && i<=j){
        if(i!=j){
            if(v[j-1]!=v[j] && v[j-1]<v[j]){
                ans = max(ans, j-i+1);
                ++j;
            }else{
                ++i;
            }
        }else{
            ++j;
        }
    }
    return ans;

}

void display(vector<int>  v){
    cout << "Print---> " << endl;
    for(auto x: v)
        cout << x << " ";
    cout << endl;
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];

    int ans1 = solve(v);
    reverse(v.begin(), v.end());
    display(v);
    int ans2 = solve(v);
    cout << ans1 << ' ' << ans2 << endl;
    cout << max(ans1, ans2) << endl;
    return 0;
}