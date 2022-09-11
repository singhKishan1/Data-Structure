#include <iostream>
using namespace std;

// using binary search we find square root in log(n) time-complexity.
int solve(int n){
    int start = 0, end = n;
    int ans = 0;
    while(start<=end){
        long long mid = start+(end-start)/2;
        if(mid*mid==n){
            ans = mid;
            break;
        }

        if(mid*mid<n){
            ans = mid;
            start = mid+1;
        }
        else end = mid-1;
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    cout << solve(n) << endl;
    return 0;
}
