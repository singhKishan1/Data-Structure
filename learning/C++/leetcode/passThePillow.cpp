#include <iostream>

using  namespace std;

int solve(int n, int t){
    int count = 1;
    bool check = true;
    while(t){
        --t;
        if(check==true)
            ++count;
        
        if(check==false)
            --count;
        
        if(count==n)
            check = false;
        else if(count==1)
            check = true;

    }

    return count;
}

int main(){
    int n,t;
    cin>>n>>t;
    cout << solve(n, t) << endl;
    return 0;
}