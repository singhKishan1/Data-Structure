#include <iostream>
#include <bitset>

using namespace std;

int solve(int n, int k){
    bitset<32> a (n);
    bitset<32> b(k);

    cout << a << endl;
    cout << b << endl;
    
    int count = 0;
    for(int i=0; i<32; ++i){
        if(a[i]==1 && a[i]!=b[i]){
            ++count;
            a[i] = 0;
        }
    }

    bool check = true;
    for(int i=0; i<32; ++i){
        if(a[i]!=b[i]){
            check = false;break;
        }
    }

    if(check)return count;

    return -1;
}

int main(){
    int n,k;
    cin>>n>>k;
    cout << solve(n, k) << endl;
    return 0;
}