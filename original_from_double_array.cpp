#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int>& arr) {
        int n = arr.size();
        if(n&1)return {};
        
        unordered_map<int, int> mp;
        for(int i=0; i<n; ++i)
            mp[arr[i]]++;
        
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for(int i=0; i<arr.size(); ++i){
            if(mp[arr[i]]==0)
                continue;
            
            if(mp[arr[i]*2]==0)
                return {};
            else if(mp[arr[i]] && mp[arr[i]*2]){
                mp[arr[i]*2]--;
                ans.push_back(arr[i]);
                mp[arr[i]]--;
            }
        }
        
        return ans;
}

int main(){
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0; i<n; ++i)cin>>v[i];
  vector<int> arr = solve(v);
  for(int i=0; i<arr.size(); ++i)cout << arr[i] << " ";
  cout << endl;
  return 0;
}
