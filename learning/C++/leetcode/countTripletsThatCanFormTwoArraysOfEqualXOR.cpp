#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> v){
    int n = v.size();
    int ans = 0;
    for(int i=0; i<n; ++i){
        int temp = v[i];
        for(int j=i+1; j<n; ++j){
            temp ^= v[j];
            if(temp==0)
                ans += j-i;
        }
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];
    
    cout << solve(v)<<endl;
    return 0;
}