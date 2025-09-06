#include <iostream>
#include <vector>

using namespace std;

void solve(vector<vector<int>>arr, int m, int n){
    vector<int> ans;

    vector<int> mns;
    for(int i=0; i<m; ++i){
        int val = arr[i][0];
        for(int j=1; j<n; ++j){
            if(arr[i][j]<val)
                val = arr[i][j];
        }

        mns.push_back(val);
    }

    vector<int>mxs;
    for(int j=0; j<n; ++j){
        int val = arr[0][j];
        for(int  i=1; i<m; ++i){
            if(arr[i][j]>val)
                val = arr[i][j];
        }

        mxs.push_back(val);
    }

    for(auto x:mns){
        for(auto y:mxs){
            if(x==y)
                ans.push_back(x);
        }
    }

    cout  <<  endl;
    for(auto x:ans)
        cout  << x << " ";
    cout << endl;
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>arr(m,vector<int>(n));
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j)
            cin>>arr[i][j];
    }

    solve(arr,m,n);

    return 0;
}