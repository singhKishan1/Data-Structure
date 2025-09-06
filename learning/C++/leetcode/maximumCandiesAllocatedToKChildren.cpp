#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> v, int k){
    int low=0,high=1e7;
    while(low < high){
        int sum = 0;
        int mid = (low + high + 1) / 2;
        for(auto x: v)
            sum += x/mid;
        
        if(k>sum)
            high = mid-1;
        else
            low = mid;
    }

    return low;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];
    
    int k;cin>>k;

    cout << solve(v, k)<< endl;
    return 0;
}