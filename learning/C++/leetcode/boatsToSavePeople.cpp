#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Return the minimum number of boats to carry every given person.
*/
int solve(vector<int> v, int limit){
    
    sort(v.begin(), v.end());
    int i=0,j=v.size(),cnt=0;
    while(i<=j){
        if(v[i]+v[j]<=limit){
            ++i;
        }
        --j;
        ++cnt;
    }

    return cnt;
}

/**
 * Main Function.
*/
int main(){
    int n;
    cin>>n;
    cout << "\nEnter element: ";
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];

    cout <<"\nEnter limit: "; 
    int limit;
    cin>>limit;

    cout << solve(v, limit) << endl;
    return 0;

}