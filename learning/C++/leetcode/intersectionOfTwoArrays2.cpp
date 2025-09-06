#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int>&a1, vector<int>&a2){
    
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());

    int p1=0,p2=0;
    vector<int> ans;
    while(p1<a1.size() && p2<a2.size()){
        if(a1[p1]<a2[p2])
            ++p1;
        else  if(a2[p2]<a1[p1])
            ++p2;
        else{
            ans.push_back(a2[p2]);
            ++p1;
            ++p2;
        }
    }

    for(auto x:ans)
        cout << x << " ";
    cout << endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr1(n),arr2(m);
    for(int i=0; i<n; ++i)cin>>arr1[i];
    for(int i=0; i<m; ++i)cin>>arr2[i];

    solve(arr1, arr2);
    return 0;
}