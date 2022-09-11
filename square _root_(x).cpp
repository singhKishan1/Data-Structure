#include <iostream>
using namespace std;
typedef long long ll;

int solve(int x){
    int low = 0, high = x;
    int ans = 0;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(mid*mid==x){
            ans = mid;
            break;
        }


        if(mid*mid<x){
            ans = mid;
            low = mid+1;
        }else
            high = mid-1;
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    int a = solve(n);
    int b = solve(n-(a*a));
    cout << a << " " << b << endl;
    if((a*a)+(b*b)==n)cout << "Yes" << endl;
    else    cout << "No" << endl;
    return 0;
}