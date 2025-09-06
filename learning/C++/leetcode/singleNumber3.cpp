#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> v){
    cout << "anser : ";
    for(auto x:v)
        cout << x << " ";
    cout << endl;
}

vector<int> solve(vector<int> v){
    int res =  0;
    for(int i=0; i<v.size(); ++i)
        res ^= v[i];
    
    int rightBitPos = 0;
    for(int i=0;i<32;++i){
        if((1<<i)&res){
            rightBitPos = i;
            break;
        }
    }

    int first = 0;
    for(int i=0; i<v.size(); ++i)
        if(v[i]&(1<<rightBitPos))
            first ^= v[i];
    
    return {first, first^res};
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];
    
    display(solve(v));
    return 0;
}