#include <iostream>
#include <vector>
using namespace std;

/*This method uses kadane's algorithm to find maximum product of subarray.*/
int maxProductSubArray(vector<int> v){
    int mx = v[0], mn = v[0], res = v[0];
    for(int i=1; i<v.size(); ++i){
        int temp = max(v[i], max(mx*v[i], mn*v[i]));
        mn = min(v[i], min(mx*v[i], mn*v[i]));
        mx = temp;

        res = max(mx, res);
    }

    return res;
}

/*Main Function*/
int main(){
    int n;  
    cin>>n;
    vector<int> v(n);
    cout <<"Enter element: ";
    for(int i=0; i<n; ++i)
        cin>>v[i];
    
    cout << maxProductSubArray(v) << endl;
}