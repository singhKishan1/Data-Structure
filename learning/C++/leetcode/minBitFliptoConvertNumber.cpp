#include <iostream>
#include <bitset>
using namespace std;

int main(){
    int start,goal;
    cin>>start>>goal;
    cout << bitset<32>(start^goal).count();
    return 0;
}