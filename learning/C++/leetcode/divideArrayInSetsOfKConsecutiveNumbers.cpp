#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve(vector<int> v, int k){
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); ++i){
        vector<int> keys;
        for(int j=0; j<v.size() && keys.size()<k; ++j){
            keys.push_back(v[j]);
        }

        if(keys.size()<k)return false;

        int x = -1;
        for(int j=1; j<keys.size(); ++j){
            if(x==-1)
                x = keys[i]-keys[i-1];
            else if(x!=(keys[i]-keys[i-1]))
                return false;
        }

        for(int j=0; j<keys.size(); ++j)
            v.erase(v.begin()+i);
    }

    return true;
}

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];
    
    int k;cin>>k;

    cout << solve(v, k) << endl;
    return 0;
}