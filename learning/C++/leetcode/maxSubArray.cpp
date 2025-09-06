#include <iostream>
#include <vector>
using namespace std;

/*Return max sum of subarray*/
int solve(vector<int> v){
    int sum = 0;
    int ans = INT32_MIN;
    for(int i=0; i<v.size(); ++i){
        sum += v[i];
        if(sum<0)
            sum = 0;
        
        ans = max(ans, sum);
    }
    return ans;
}

/*Main  Function*/
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];
    
    cout << solve(v) << endl;
    return 0;
}