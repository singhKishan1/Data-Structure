#include <iostream>

using namespace std;

int solve(int target, int maxDoubles){
    int cnt = 0;
    while(target>1 && maxDoubles){
        if(target&1)
            --target;
        else{
            target /=2;
            --maxDoubles;
        }
        ++cnt;
    }

    if(target==1)
        return cnt;
    
    return cnt+target-1;
}

int main(){
    int target, maxDoubles;
    cin>>target>>maxDoubles;
    cout << solve(target, maxDoubles) << endl;
    return 0;
}