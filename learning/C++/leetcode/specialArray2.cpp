#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void solve(vector<int>&v,vector<vector<int>>queries){
    int n = v.size();
    int m = queries.size();
    unordered_set<int> st;
    for(int i=1; i<n; ++i){
        if((v[i-1]&1 && v[i]&1)||(v[i-1]&1==0 && v[i]&1==0)){
            st.insert(i-1);
        }
    }

    vector<bool> ans;
    for(int i=0; i<m; ++i){
        if(st.find(queries[i][0])!=st.end())
            ans.push_back(true);
        else
            ans.push_back(false);
    }

    for(auto x:ans)
        cout << x << "\t";
    cout << endl;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)  
        cin>>v[i];
    

}