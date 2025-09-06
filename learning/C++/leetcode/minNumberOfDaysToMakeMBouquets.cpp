#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solve(vector<int> v, int m, int k){
    int n = m;
    priority_queue<int, vector<int>,greater<int>> pq;
    
    int ans = 0;
    int cnt = 0;
    while(m>=0 && pq.size()>0){
        int val = pq.top();
        ++cnt;
        if(cnt==k){
            ans += val;
            cnt = 0;
            --m;
        }
        pq.pop();

    }

    return m==n?-1 : ans;    
}

int main(){
    int n;
    cin>>n;
    vector<int> bloomDay(n);
    for(int i=0; i<n; ++i)cin>>bloomDay[i];

    int m,k;cin>>m>>k;

    cout << solve(bloomDay, m, k) << endl;
    return 0;
}