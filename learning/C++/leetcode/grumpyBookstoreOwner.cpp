#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &c, vector<int> &g, int mi){
    int n = c.size();
    int l=-1,r=-1;
    int i=0,j=0;
    int mxSum = 0, sum=0, cnt=0;
    while(j<n){
        if(g[j]==1)
            ++cnt;
        
        sum += c[j];

        if(j-i+1==mi){
            if(cnt>0){
                mxSum = max(mxSum, sum);
                l = i,r=j;
            }

            if(g[i]==1)
                --cnt;
            
            sum -= c[i];
            ++i;
        }

        ++j;
    }

    int ans = 0;
    for(int k=0; k<n; ++k){
        if(k>=l && k<=r){
            ans += mxSum;
            k=r;
        }else if(g[i]==0)
            ans += c[i];
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> cust(n), grump(n);
    for(int i=0; i<n; ++i)cin>>cust[i];
    for(int i=0; i<n; ++i)cin>>grump[i];

    int minutes;cin>>minutes;

    cout << solve(cust, grump, minutes) << endl;
    return 0;
}