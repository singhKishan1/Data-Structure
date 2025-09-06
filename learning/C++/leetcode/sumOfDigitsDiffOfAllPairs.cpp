#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> v){
    int ans = 0;
    for(int i=0; i<v.size(); ++i){
        
        for(int j=i+1; j<v.size(); ++j){
            int x = v[j];
            int num = v[i];
            while(x){
                ans += abs((x%10) - (num%10));
                x = x/10;
                num = num/10;
            }
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
    
    cout << solve(v) << endl;
    return 0;
}