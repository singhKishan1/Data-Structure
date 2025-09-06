#include  <iostream>
#include <vector>

using namespace std;

void  solve(vector<int>rSum, vector<int>cSum, int m, int n){
    
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<int>rSum(m),cSum(n);
    for(int  i=0; i<m; ++i)
        cin>>rSum[i];
    
    for(int i=0; i<n; ++i)
        cin>>cSum[i];
    

    solve(rSum, cSum, m,n);
    return 0;
}