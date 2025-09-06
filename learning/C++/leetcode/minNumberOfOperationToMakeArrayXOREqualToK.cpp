#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int solve(vector<int> v,int k){
    int ans = 0;
    for(int i=0; i<v.size(); ++i)
        ans ^= v[i];
    
    return bitset<32>(ans^k).count();
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)  
        cin>>v[i];
    
    int k;cin>>k;
    cout << solve(v, k) <<  endl;

    return 0; 
}