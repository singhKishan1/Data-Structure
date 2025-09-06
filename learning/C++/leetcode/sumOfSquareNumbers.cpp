#include <iostream>
#include <cmath>

using namespace std;

int main()
{   
    int n;
    cin>>n;

    int x = sqrtf32(n);
    
    int y = sqrtf32(n-(x*x));
    float z = sqrtf32(n-(x*x));


    cout << (y==z) << endl;

    return 0;
}