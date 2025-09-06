#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solve(vector<int> &v, int k){
    int n = v.size();
    unordered_map<int, int>mp;
    for(auto x:v)
        mp[x]++;
    

    sort(v.begin(),v.end());
    vector<vector<int>> arr;
    for(int i=0; i<n; ++i){
        if(mp.find(v[i])!=mp.end()){
            int val = v[i];
            mp[val]--;
            if(mp[abs(val-k)]>0){
                vector<int> t{abs(val-k), val};
                sort(t.begin(), t.end());
                arr.push_back(t);
                mp.erase(val);
                mp.erase(abs(val-k));
            }else{
                mp[val]++;
            }
        }
    }

    int ans = arr.size();
    for(int i=0; i<n; ++i){
        
        if(mp.find(v[i])!=mp.end()){
            bool check  = false;
            for(auto y:arr){
                if(v[i]>y[0] && v[i]<y[1]){
                    check  = true;break;
                }
            }

            if(!check)++ans;
        }
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)cin>>v[i];

    int k;cin>>k;
    cout<< solve(v,k) <<endl;
    return 0;
}