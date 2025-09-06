#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>


using namespace std;


typedef pair<int, int> pd;

int bSearch(vector<pd> v, vector<int> mx, int val){
    int i=0,j=v.size()-1;
    int ans = 0;
    while(i<=j){
        int mid = i+(j-i)/2;
        if(val<v[mid].first)
            j = mid-1;
        else{
            ans = max(mx[mid], ans);
            i = mid+1;
        }
    }

    return ans;
}

int solve(vector<int> diff, vector<int> prf, vector<int> wrk){
    int n = diff.size();
    vector<pd> v(n);
    for(int i=0; i<n; ++i)
        v[i] = {diff[i], prf[i]};
    
    sort(v.begin(), v.end());

    vector<int> mx(n+1,0);
    for(int i=1; i<=n; ++i)
        mx[i] = max(mx[i-1], v[i-1].second);


    int ans = 0;
    for(int i=0; i<wrk.size(); ++i)
        ans += bSearch(v, mx, wrk[i]);
    
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> difficulty(n), profit(n);
    for(int i=0; i<n; ++i)cin>>difficulty[i];
    for(int i=0; i<n; ++i)cin>>profit[i];

    int m;
    cin>>m;
    vector<int> worker(m);
    for(int i=0; i<m; ++i)cin>>worker[i];

    cout << solve(difficulty, profit, worker) << endl;
    return 0;
}