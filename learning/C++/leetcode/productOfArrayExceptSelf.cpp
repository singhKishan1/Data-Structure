#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

/*Function who display the element of array.*/
void display(vector<int> v)
{
    cout << "\nElement of array.";
    for (auto x : v)
    {
        cout << x << " ";
    }

    cout << endl;
}

/*Function Who solve the product f array ExceptSelf.*/
vector<int> productOfArrayExceptSelf(vector<int> v)
{
    int n = v.size();
    vector<int> ans(n);
    ll prev = 1;
    for(int i=0; i<n; ++i){
        ans[i] = prev;
        prev = prev*v[i];
    }

    prev = 1;
    for(int i=n-1; i>=0; --i){
        int temp = v[i];
        v[i] = prev;
        prev = temp*prev;
    }


    display(ans);
    display(v);

    for(int i=0; i<n; ++i){
        ans[i] = ans[i]*v[i];
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << "\nEnter element in array: " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    display(productOfArrayExceptSelf(v));
    return 0;
}