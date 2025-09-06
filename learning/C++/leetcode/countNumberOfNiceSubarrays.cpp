#include <iostream>
#include <vector>

using namespace std;


int solve(vector<int>&v, int k){
    int start=-1,end=-1;
    int i=0,j=0,n=v.size(), cnt=0;
    int ans = 0;

    int t=0;
    while(j<n){
        if(v[j]%2==1){
            ++cnt;
            if(start==-1)
                start = j;
            
            end = j;
        }
        

        if(cnt>k){
            i = start+1;
            while(cnt!=k){
                if(v[start]%2==1)--cnt;
                ++start;
            }

            while(start<=end && v[start]%2==0){
                ++start;
            }
        }

        if(cnt==k){
            ans += start-i+1;
        }
        ++j;
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)cin>>v[i];

    int k;cin>>k;
    cout << solve(v, k ) << endl;
    return 0;
}