#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> arr;
void dfs(vector<int>&v, int id,vector<int>&op, int k){

    if(id>=v.size()){
        if(op.size()>0)
            arr.push_back(op);
        
        return;
    }

    for(int i=id; i<v.size(); ++i){
        if(op.size()==0){
            op.push_back(v[i]);
            dfs(v, i+1, op, k);
            op.pop_back();
        }else if(op.size()>0 and abs(op.back()-v[i])!=k){
            op.push_back(v[i]);
            dfs(v, i+1, op, k);
            op.pop_back();
        }else{
            dfs(v, i+1, op, k);
        }
    }

}

int solve(vector<int> v, int k){
    sort(v.begin(), v.end());
    vector<int> op;
    dfs(v, 0,op,k);
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];

    int k;
    cin>>k;
    cout << solve(v,k) <<endl;

    cout << "\n\nArray:\n";
    for(auto x:arr){
        for(auto y: x)
            cout << y<<  " ";
        cout << endl;
    }
    return 0;
}