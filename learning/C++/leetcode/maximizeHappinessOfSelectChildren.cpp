#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(vector<int> v, int k){
    sort(v.begin(), v.end(), greater<int>());
    long long sum = 0;
    for(int i=0; i<k && v[i]-i>0; ++i){
        sum += v[i]-i;
    }

    return sum;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];
    
    int k;cin>>k;

    cout << solve(v, k) << endl;
    return 0;
}