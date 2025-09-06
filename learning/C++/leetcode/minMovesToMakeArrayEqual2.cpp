#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> v){
    sort(v.begin(), v.end());
    int n = v.size();
    int mid = n/2;

    int moves = 0;
    for(int i=0; i<n; ++i){
        moves += abs(v[mid]-v[i]);
    }

    return moves;
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