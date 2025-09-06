#include <iostream>
#include <vector>
using namespace std;

/*Count the number of subarrays*/
int countSubArrays(int n)
{
    return n * (n + 1) / 2;
}

/*It will return the number of subarray who's product is strictly less than k.*/
int subArrayProductLessThanK(vector<int> v, int k)
{
    int count = 0;
    int i = 0, j = 0, n = v.size();
    int pd = 1;
    while(j<n){
        pd *= v[j];
        while(pd>=k && i<j){
            pd = pd/v[i++];
        }

        count += (j-i+1);
        ++j;
    }

    return count;
}

/*Main function*/
int main()
{
    int n, k;
    cin >> n >> k;
    cout << "Enter element in array: ";
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cout << subArrayProductLessThanK(v, k) << endl;
    return 0;
}