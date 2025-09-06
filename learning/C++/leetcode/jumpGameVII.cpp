#include <iostream>
#include <vector>
using namespace std;

int jumpGameVII(string s, int minJump, int maxJump){
    int n = s.size();
    vector<bool> dp (n, false);
    int pre = 0;
    dp[0] = true;
    for(int i=1; i<n; ++i){
        if(i>=minJump)
            pre += dp[i-minJump];
        
        if(i>maxJump)
            pre -= dp[i-maxJump-1];
        
        dp[i] = pre>0 && s[i]=='0';
    }

    return dp[n-1];
}


/**
 * Main Function.
*/
int main(){
    string s;cin>>s;
    int minJump,maxJummp;cin>>minJump>>maxJummp;
    cout << jumpGameVII(s, minJump, maxJummp) << endl;
    return 0;
}