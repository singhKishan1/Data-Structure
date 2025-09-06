#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void dfs(vector<int> &v, int id, vector<int>& op, int target, set<vector<int>>  &st){
    if(target==0){
        st.insert(op);
        return;
    }

    if(id>=v.size())
        return;
    
    if(v[id] <= target){
        op.push_back(v[id]);
        dfs(v, id+1, op, target-v[id], st);
        op.pop_back();
    }

    dfs(v, id+1, op, target, st);
}


void solve(vector<int> v, int target){
    sort(v.begin(), v.end());
    set<vector<int>> st;
    vector<int> op;
    dfs(v, 0, op, target, st);
    for(auto x: st){
        for(auto y: x)
            cout << y << "\t";
        cout << endl;
    }
}

int main(){
    // int n;
    // cin>>n;
    // vector<int> v(n);
    // for(int i=0; i<n; ++i)
    //     cin>>v[i];
    
    int target;
    cin>>target;
    
    solve({1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, target);

    return 0;
}