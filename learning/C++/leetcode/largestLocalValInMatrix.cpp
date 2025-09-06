#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solve(vector<vector<int>> v){
    int n = v.size();
    vector<vector<int>> ans(n-2, vector<int>(n-2));
    for(int i=0; i<n-2; ++i){
        for(int j=0; j<n-2; ++j){
            int temp = 0;
            for(int  l=i,cnt=0; l<n && cnt<3;  ++l, ++cnt){
                temp = max(temp, *max_element(v[l].begin()+j, v[l].begin()+j+3));
            }

            ans[i][j] = temp;
        }
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin>>v[i][j];
        

    vector<vector<int>> ans = solve(v);
    for(auto x:ans){
        for(auto y: x)
            cout << y  << "\t";
        cout << endl;
    }

    return 0;
}