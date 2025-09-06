#include <iostream>
#include <stack>
using namespace std;

bool solve(string s1, string s2){
    int n = s1.size();
    cout << n << endl;
    if(n&1)
        return false;

    int balance = 0;
    for(int i=0; i<n; ++i){
        if(s2[i]=='1' && s1[i]==')')
            --balance;
        else
            ++balance;
        

        if(balance<0)return false;
    }

    balance = 0;
    for(int i=n-1; i>=0; --i){
        if(s2[i]=='1' && s1[i]=='(')
            -balance;
        else
            ++balance;

        
        if(balance<0)return false;
    }

    return true;

}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout << solve(s1, s2) << endl;
    return 0;
}