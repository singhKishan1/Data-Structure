#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<float, vector<int>> pd;
vector<int> solve(vector<int> v, int k){
    priority_queue<pd> pq;
    for(int i=0; i<v.size(); ++i){
        for(int j=i+1; j<v.size(); ++j){
            float div = (float)v[i]/(float)v[j];
            pq.push({div, {v[i],v[j]}});
            if(pq.size()>k)
                pq.pop();
        }
    }

    return pq.top().second;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin>> v[i];
    
    int k;cin>>k;

    vector<int> ans = solve(v, k);
    cout << "{ " << ans[0] << " , " << ans[1] << " }" << endl;
    return 0;
}