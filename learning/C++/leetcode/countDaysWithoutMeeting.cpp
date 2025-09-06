#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void solve(vector<vector<int>> mt, int days){
    
    sort(mt.begin(), mt.end());

    vector<vector<int>>v;
    v.push_back(mt[0]);
    for(int  i=1; i<mt.size(); ++i){
        if()
    }

}


/*Main function
@returns 0;
*/
int main(){

    int days;
    cin>>days;

    int n;cin>>n;
    vector<vector<int>> mt(n,vector<int>(2));

    for(int i=0; i<n; ++i)
        cin>>mt[i][0]>>mt[i][1];
    
    solve(mt, days);
    return 0;

}