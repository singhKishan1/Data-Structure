#include <iostream>
#include <bitset>
using namespace std;

int solve(int a, int b, int c)
{
    int mask = (a | b) ^ c;
    return bitset<32>(mask).count() + bitset<32>(mask & a & b).count();
}

// int solve(int a, int b, int c){
//     int cnt = 0;
//     for(int i=0; i<32; ++i){
//         if((a|b)==c)
//             return cnt;

//         int mask = 1<<i;
//         if(c&mask){

//             if(!(b&mask) && !(a&mask)){
//                 a = a^mask;
//                 cout << a << endl;
//                 ++cnt;
//             }
//         }else{
//             bool check = false;
//             if(b&mask){
//                 ++cnt;
//                 check = true;
//             }

//             if(a&mask){
//                 ++cnt;
//                 check = true;
//             }

//             if(check)
//                 a = a^mask;
//         }
//     }

//     return cnt;
// }

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << endl;
    return 0;
}