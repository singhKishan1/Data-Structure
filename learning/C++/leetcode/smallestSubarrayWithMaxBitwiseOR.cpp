#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int orOperation(vector<int> &bitHolder, int num, int res){
    for(int i=0; i<32; ++i){
        if((1<<i)&num)
            bitHolder[32-i-1]++;
    }

    cout << (num|res) << endl;
    return num|res;
}

int removeFromOrSum(vector<int>&bitHolder, int num){
    for(int i=0; i<32; ++i){
        if((1<<i)&num)
            bitHolder[32-i-1]--;
    }

    int sum = 0;
    for(int i=0; i<bitHolder.size(); ++i){
        if(bitHolder[32-i-1]>0)
            sum += (1<<i);
    }

    return sum;
}

void solve(vector<int> &v){
    int mx = 0;
    for(int i=0; i<v.size(); ++i)
        mx = max(mx, v[i]);
    
    vector<int> ans;

    vector<int> bitHolder(32,0);
    int count = 0;
    int sum = 0;
    for(int i=0,j=0; j<v.size(); ++j){
        
        sum = orOperation(bitHolder, v[j], sum);
        if(sum==mx){
           while(i<=j && sum==mx){
                ans.push_back(j-i+1);
                sum = removeFromOrSum(bitHolder, v[i]);
                ++i;
           }
        }
    }

    for(auto x:ans){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];
    
    solve(v);
    return 0;
}