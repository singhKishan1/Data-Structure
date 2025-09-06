#include <iostream>

using namespace std;

string solve(string ch1, string ch2, int mx, int mn){

    string ans = "";
    while(mx>0 || mn>0){
        if(mx>mn && mx>1){
            ans += ch1+ch1;
            mx -=2;
        }else if(mx>0){
            ans += ch1;
            --mx;
        }

        if(mn>0){
            ans += ch2;
            --mn;
        }
    }

    return ans;
}

int main(){
    int a,b;
    cin>>a>>b;

    string ans = "";
    if(a==b){
        while(a>0){
            ans += "ab";
            --a;
        }
    }else{
        if(a>b){
            ans = solve("a", "b", a, b);
        }else{
            ans = solve("b", "a", b, a);
        }
    }

    cout << ans << endl;
    return 0;
}