#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solve(vector<int> v){
    int n = v.size();
    int mn = INT32_MAX;
    int sum = 0;
    for(int i=0; i<n; ++i){
        sum += v[i];
        mn = min(mn, v[i]);
    }

    return sum - (n*mn);
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];

    cout << solve(v) <<endl;
    return 0;

}