#include "iostream"
using namespace std;

int main(){
    int n;
    cin>>n;
    int val = 0;
    while(n>0){
        val = val*10 + n%10;
        n/=10;
    }

    cout << val << endl;
    return 0;
}