#include <iostream>
#include <vector>

using namespace std;

int main(){
  int m, n;
  cin>>m>>n;
  vector<vector<int>> arr;
  for(int i=0; i<m; ++i){
    vector<int>v(n);
    for(int j=0; j<n; ++j)
       cin>>v[j];
    arr.push_back(v);
  }
  
  for(int i=n-2; i>=0; --i)
     arr[m-1][i] += arr[m-1][i+1];
 
  for(int i=m-2; i>=0; --i)
    arr[n-1][i] += arr[n-1][i+1];
  
  for(int i=m-2; i>=0; --i){
    for(int j=n-2; j>=0; --j){
      arr[i][j] += min(arr[i+1][j], arr[i][j+1]);
    }
  }
  cout << arr[0][0] << endl;
  return 0;
}
