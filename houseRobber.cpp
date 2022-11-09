#include <iostream>
#include <vector>
using namespace std;

int mp[104];

int solve(vector<int> v, int n){
  if(n<=0)
      return 0;
 
  if(mp[n]!=-1)
      return m[n];
 
  return mp[n] = max(solve(v, n-2)+v[n-1], solve(v, n-1));
}

int main(){
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0; i<n; ++i)
      cin>>v[i];
  
  cout << solve(v, n) << endl;
  return 0;
}
