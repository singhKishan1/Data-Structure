#include <iostream>
#include <cmath>
using namespace std;

int solve(int arr[], int n)
{
    int bitCounter[32] = {0};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 32; ++j)
        {
            if ((1 << j) & arr[i]){
                bitCounter[j]++;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<32; ++i)
        ans += bitCounter[i]%3*pow(2, i);

    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << solve(arr, n) << endl;
    return 0;
}