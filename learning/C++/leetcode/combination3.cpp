#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>&arr, vector<int>&op, int sum, int pos, int k, int n){
    if(op.size()==k){
        if(sum==n){
            cout << "sum --> " << sum << ", n---> " << n  << endl;
            arr.push_back(op);
        }
            
        
        return;
    }

    for(int i=pos; i<=n; ++i){
        if(sum+i<=n){
            op.push_back(i);
            dfs(arr, op, sum+i, i+1,k,n);
            op.pop_back();
        }else  break;
    }

}

void solve(int k, int n){
    vector<vector<int>> arr;
    vector<int>op;
    int  sum  = 0;
    for(int i=1; i<=n; ++i){
        op.push_back(i);
        dfs(arr, op, i, i+1, k, n);
        op.pop_back();
    }

    for(auto  x:arr){
        for(auto  y:x)
            cout << y <<  " ";
        cout <<  endl;
    }
}

int main(){
    int k,n;
    cin>>k>>n;

    solve(k, n);
    return 0;
}