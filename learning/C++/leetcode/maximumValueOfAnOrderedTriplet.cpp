#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll maximumValueOfAnOrderedTriplet(vector<int> &v)
{

    int n = v.size();
    vector<int>  mxl(n), mxr(n);

    for(int i=1; i<n; ++i)
        mxl[i] = max(mxl[i-1], v[i-1]);

    for(int i=n-2; i>=0; --i)
        mxr[i] = max(mxr[i+1], v[i+1]);
    

    ll ans = 0;
    for(int i=1; i<n-1; ++i)  {
        ans = max(ans, (ll)(mxl[i] - v[i]) * mxr[i]);
    }    

    return ans;
}

int main()
{
    vector<int> v = {12, 6, 1, 2, 7};

    cout << maximumValueOfAnOrderedTriplet(v) << endl;

    vector<int> v2 = {1,10,3,4,19};
    cout << maximumValueOfAnOrderedTriplet(v2) << endl;

    vector<int> v3 = {1, 2, 3};
    cout << maximumValueOfAnOrderedTriplet(v3) << endl;
    return 0;
}