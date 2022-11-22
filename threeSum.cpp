#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int> v){
  int n = v.size();
  set<vector<int>> s;
  sort(v.begin(),v.end());
  for(int i=0; i<n-2; ++i){
    int j=i+1, k=n-1;
    while(j<k){
      int sum = v[j]+v[k];
      if(sum == -v[i]){
        s.insert({v[i], v[j], v[k]});
      }
      
      if(sum>-v[i])--k;
      
      if(sum<v[i])++j;
    }
  }
  
  vector<vector<int>> arr;
  for(auto x:s)
     arr.push_back(x);
  
  return arr;
}

int main(){
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0; i<n; ++i)
    cin>>v[i];
   
  vector<vector<int>> arr = solve(v);
  for(auto x:arr){
    for(int i=0; i<x.size(); ++i)
      cout << x[i] << " ";
    cout << endl;
  }
  cout << endl;
  return 0;
}
