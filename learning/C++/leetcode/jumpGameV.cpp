#include <iostream>
#include <vector>

using namespace std;

/**
 * Function return max jump for particular index.
*/
int solve(vector<int> &v, int i, vector<int> &dp, int d){
    if(dp[i])return dp[i];
    int n = v.size();

    int mxRange = min(i+d, n-1), mnRange = max(i-d, 0), res = 1;
    
    // traversing from left->right;
    for(int j=i+1; j<=mxRange && v[i]>v[j]; ++j)
        res = max(res, 1+solve(v, j, dp, d));

    // traversing from right->left.
    for(int j=i-1; j>=mnRange && v[i]>v[j]; --j)
        res = max(res, 1+solve(v, j, dp, d));
    
    return dp[i] = res;
}

/**
 * max number of jump 
*/
int jumpGameV(vector<int> v, int d){
    int res = 1;
    vector<int> dp(v.size(), 0);
    for(int i=0; i<v.size(); ++i)
        res = max(res, solve(v, i, dp, d));
    
    return res;
}

/**s
 * Main Function
*/
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    cout << "Enter element in array: ";
    for(int i=0; i<n; ++i)
        cin>>v[i];
    
    int d;cin>>d;
    cout << jumpGameV(v, d) << endl;
    return 0;
}